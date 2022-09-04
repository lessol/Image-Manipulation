/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#include "manip.h"
#include "Pixel.h"
#include "Image.h"

/*************************************************************
 *                gray_scale manipulation                    *
 * Passed   : Image object reference                         *
 * Purpose  : Apply grayscale filter to passsed image object *
  ************************************************************/
void gray_scale(Image &grayImg) {
	int avg = 0; // average for creating image grayscale

	Header header = grayImg.header();
	vector<Pixel> gray = grayImg.pixels();

   // iterate through the content of the image 
   for(int i = 0; i < header.width() * header.height(); i++) {
		// calculate the average of the r, g, b values for the pixel
		avg = (grayImg.pixels().at(i).r() + grayImg.pixels().at(i).g() + grayImg.pixels().at(i).b()) / 3;

		avg = static_cast <unsigned char> (avg);
		// assign avg to each r, g, b value of the pixel
      gray.at(i).setVal(avg);
   }

   // set the pixel of copy image to gray
   grayImg.setPixel(gray);
}

/*************************************************************
 *                mirror manipulation                        *
 * Passed   : Image object reference                         *
 * Purpose  : Apply mirror effect to passsed image object    *
  ************************************************************/
void mirror(Image &mirrorImg) {
	int row = 0; // num of rows in image
  int col = 0; // num of columns in image

	const int center = (mirrorImg.header().width() / 2);

	// loop traversing the pixels of the image 
   for(row = 0; row < mirrorImg.header().height(); row++) {
      for(col = 0; col < center ; col++) {   
        swap(mirrorImg(row,col), mirrorImg(row,mirrorImg.header().width() - col - 1));
      }
   }

}

/*************************************************************
 *                green_screen manipulation                  *
 * Passed   : Image object reference                         *
 * Purpose  : Apply greenscreen to passsed image object      *
  ************************************************************/
void green_screen(Image &img, Image &clemsonImg) {
	Header header = img.header(); // header info
	vector<Pixel> gs = clemsonImg.pixels();
	vector<Pixel> greenScreen = img.pixels();

  // iterate through the content of the image 
  for(int i = 0; i < header.width() * header.height(); i++) {
  	if(gs.at(i).r() != 0 && gs.at(i).g() != 128
  			&& gs.at(i).b() != 0) {

  		greenScreen.at(i).r() = gs.at(i).r();
  		greenScreen.at(i).g() = gs.at(i).g();
  		greenScreen.at(i).b() = gs.at(i).b();
  	}
  }

  // apply greenscreen to disney image
  img.setPixel(greenScreen);
}