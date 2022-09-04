/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#include "Image.h"
using namespace std;

/*************************************************************
 *                Image copy Constructor             		 *
 * Passed   : Image object reference             			 *
 * Purpose  : Initialize Image object with reference Image   *
  ************************************************************/
Image::Image(const Image &img) {
	the_Header = img.header();
	the_Pixel = img.pixels();
}


/*************************************************************
 *                Image Parametrized Constructor             *
 * Passed   : ifstream image file                			 *
 * Purpose  : Initialize Image object via image file         *
  ************************************************************/
Image::Image(ifstream &file) {
	the_Header = Image::read_header(file);
	the_Pixel = Image::read_pixels(the_Header, file);
}

/*************************************************************
 *                      destructor     						 *
 * Purpose  : destroy Image objects		    	 		     *
  ************************************************************/
Image::~Image() {
}

// read data from image file into header object
/*************************************************************
 *                	  	read_pixels          	             *
 * Passed   : header object reference and ifstream image file*
 * Purpose  : read the pixels info of image file 	 	 	 *
  ************************************************************/
vector<Pixel> Image::read_pixels(const Header &obj, ifstream &file) {
	unsigned char r,g,b; // rgb variables

	int num = obj.width() * obj.height();

	vector<Pixel> data(num); // vector of Pixels

	for (Pixel& temp: data) {
		r = file.get(); // using get() to read individual characters
		g = file.get();
		b = file.get();
		temp = Pixel(r, g, b); // instantiate temp with Pixel constructor
	}

	// return vector of Pixels
	return data; 
}

/*************************************************************
 *                	  	read_header          	             *
 * Passed   : ifstream image file 	             			 *
 * Purpose  : read the header info of image file 	 	 	 *
  ************************************************************/
Header Image::read_header(ifstream &file) {
	int theWidth, theHeight, theMC;
	string theMagic_val;

	file >> theMagic_val;
	file >> theWidth;
	file >> theHeight;
	file >> theMC;

	// ignore chars grom input buffer until newline
	file.ignore(256, '\n'); 

	Header theHeader(theMagic_val, theWidth, theHeight, theMC);

	return theHeader;
}

/*************************************************************
 *                Image assignment operator                  *
 * Passed   : Address of Image object             			 *
 * Purpose  : Assign Image object members to other Image obj *
  ************************************************************/
Image& Image::operator=(const Image &obj) {

	if (this == &obj) 
		return *this;

	this->the_Header = obj.header();
	this->the_Pixel = obj.pixels();

	return *this;
}
 
/*************************************************************
 *                Overloaded parentheses operator            *
 * Passed   : two ints             			                 *
 * Purpose  : Access a pixel using (x,y) notation to return  *
  ************************************************************/
Pixel& Image::operator()(int x, int y) {
	int accessPoint = (x * this->the_Header.width()) + y;
	return this->the_Pixel[accessPoint];
}


/*************************************************************
 *                	      write_header            			 *
 * Passed   : ofstream file             			         *
 * Purpose  : Write image header to a file  			   	 *
  ************************************************************/
void Image::write_header(ofstream &outfile) const{
	outfile<<this->the_Header.ppmType()<<" "<<this->the_Header.width() <<" "
	<<this->the_Header.height()<<" "<<this->the_Header.max_color()<<endl;
}

/*************************************************************
 *                	      write_to               			 *
 * Passed   : ofstream file             			         *
 * Purpose  : Write pixel info to a file   	  			   	 *
  ************************************************************/
void Image::write_to(ofstream &outfile) const{
	write_header(outfile);

	// // iterate through data
	for (int i = 0; i < this->header().width() * this->header().height(); ++i) 
		outfile<<this->pixels().at(i).r()<<this->pixels().at(i).g()<<this->pixels().at(i).b();
	// for (const Pixel& val: this->the_Pixel) {
	// 	outfile<<val.r()<<val.g()<<val.b(); // write pixel data to image file
	// }
	
}

/*************************************************************
 *               const header getter		  	             *
 * Purpose  : get header of Image object 			    	 *
  ************************************************************/
const Header& Image::header() const {return this->the_Header;}

/*************************************************************
 *               const pixel getter		  		             *
 * Purpose  : get pixel of Image object 			    	 *
  ************************************************************/
const vector<Pixel>& Image::pixels() const {return this->the_Pixel;}

/*************************************************************
 *               	  set pixel 		  		             *
 * Purpose  : set the pixels of Image object 			     *
  ************************************************************/
void Image::setPixel(const vector<Pixel> &obj) {
	this->the_Pixel.clear();
	for(int i = 0; i < this->header().width() * this->header().height(); i++) {
		this->the_Pixel.push_back(obj.at(i));
	}
}
