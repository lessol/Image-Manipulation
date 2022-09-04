/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#ifndef IMAGE_H
#define IMAGE_H

//libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "Pixel.h"
#include "Header.h"

using namespace std;

// Image Class
class Image{
private:
	Header the_Header;
	vector<Pixel> the_Pixel;

public:

	Image() {} // Default Constructor not used. 

	Image(const Image &img); // Image copy constructor

	Image(ifstream &file); // Image file constructor

	~Image(); // Destructor

	Image& operator=(const Image &obj); // assignment operator

	// Overloaded parentheses to access a pixel using (x,y) notation 
	Pixel& operator()(int x, int y);

	// write header for image to be created
	void write_header(ofstream &out) const;

	// write to image file
	void write_to(ofstream &outfile) const;

	// read data from image file into header object
	vector <Pixel> read_pixels(const Header &obj, ifstream &file);

	// read header data 
	Header read_header(ifstream &file);

	// constant reference getters
	const Header& header() const;	// get header

	const vector<Pixel>& pixels() const; // get Pixel vector

	// set the pixels of an image
	void setPixel(const vector<Pixel> &obj);


};


#endif
