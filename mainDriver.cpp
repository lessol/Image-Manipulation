/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#include "Image.h"
#include "Pixel.h"
#include "Header.h"
#include "manip.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// function prototype
int printMenu();
int whichImage();

int main(int argc, char* argv[]) {
	int userSelection = 2;
	int imgChoice, imageCount = 0;
	string count, outImage;

	// check for correct number of arguments entered on the command-line
   if(argc != 3) {
      printf("USAGE: <executable> <firstImage> <secondImage>\n\n");
      return -1;
   }

   // two input file pointers to open ppm images
   ifstream oneImage(argv[1]);
   ifstream twoImage(argv[2]);

   // check that the files opened successfully
   if(!oneImage || !twoImage) {
      printf("ERROR: File(s) could not be opened.\n");
      exit(1);  
   }

   // instantiate images for each file ptr
   Image Clemson(oneImage);
   Image Disney(twoImage); 

   // close input files for images
   oneImage.close();
   twoImage.close();

   // while loop until user decides to exit
   while (userSelection != 0) {

   	// print menu and obtain user's choice of manipulation
   	userSelection = printMenu();

	    // exit program
	    if (userSelection == 0) {
	    	continue;
	    }

	    switch (userSelection) {

	    	// grayscale
	    	case 1:
	    	{
		    	imgChoice = whichImage(); // user input
		    	if (imgChoice == 1) {
		    		Image grayClemson = Clemson;
		    		gray_scale(grayClemson);
		    		count = to_string(imageCount);
		    		outImage = "out_"+count+".ppm"; // image name
		    		ofstream gray_output(outImage); // create output file
		    		grayClemson.write_to(gray_output); // write to file
		    		gray_output.close();					 // close file
		    		++imageCount;
		    	}
		   
		    	if (imgChoice == 2) {
		    		Image grayDisney = Disney;
		    		gray_scale(grayDisney);
		    		count = to_string(imageCount);
		    		outImage = "out_"+count+".ppm";
		    		ofstream gray_output(outImage);
		    		grayDisney.write_to(gray_output);
		    		gray_output.close();
		    		++imageCount;
		    	}

		    	break;
		    }

		   // mirror
	    	case 2:
	    	{
		    	imgChoice = whichImage();
		    	if (imgChoice == 1) {
		    		Image mirrorClemson = Clemson;
		    		mirror(mirrorClemson);
		    		count = to_string(imageCount);
		    		outImage = "out_"+count+".ppm";
		    		ofstream mirror_output(outImage);
		    		mirrorClemson.write_to(mirror_output);
		    		mirror_output.close();
		    		++imageCount;
		    	}
		    	if (imgChoice == 2) {
		    		Image mirrorDisney = Disney;
		    		mirror(mirrorDisney);
		    		count = to_string(imageCount);
		    		outImage = "out_"+count+".ppm";
		    		ofstream mirror_output(outImage);
		    		mirrorDisney.write_to(mirror_output);
		    		mirror_output.close();
		    		++imageCount;
		    	}
		    	
		    	break;
		   }

		   //greenscreen
	    	case 3:
	    	{
		    	Image copy = Disney;
		    	cout<<"The Clemson Paw will be copied on top of the Disney image."<<endl;
		    	green_screen(copy, Clemson);
		    	count = to_string(imageCount);
		    	outImage = "out_"+count+".ppm";
		    	ofstream output(outImage);
		    	copy.write_to(output);
		    	output.close();
		    	++imageCount;
		    	break;
		   	}

		   default: {
		   	cout<<"Something went wrong! Please try again!"<<endl;
		    	break;
		    }

	   	}

   }

}

// function definition
int printMenu() {
   int userChoice; // user choice for image manipulation

   // display menu
   cout<<endl<<"PA2 Image Manipulation"<<endl;
   cout<<"0. exit program"<<endl;
   cout<<"1. gray scale"<<endl;
   cout<<"2. mirror"<<endl;
   cout<<"3. green screen"<<endl;

   // read user choice for image manipulation
   cin >> userChoice;
   cout<<"- - > "<<userChoice<<endl;

   return userChoice;
}

int whichImage() {
	int imageChoice; // user choice for image manipulation

   	// display menu
   	cout<<endl<<"PA2 Image Manipulation"<<endl;
   	cout<<"1. ClemsonPaw.ppm"<<endl;
   	cout<<"2. Disney.ppm"<<endl;

   	cin>>imageChoice;
   	cout<<"- - > "<<imageChoice<<endl;

   	return imageChoice;
}