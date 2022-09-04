/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#ifndef PIXEL_H
#define PIXEL_H

// libraries
#include <iostream>
using namespace std;

class Pixel{
private:
	unsigned char R, G, B;
public:
	Pixel(); // default contstructor
	Pixel(unsigned char x, unsigned char y, unsigned char z); // rgb constructor
	Pixel(const Pixel &obj); // Pixel copy constructor

	~Pixel(); // destructor
	
	// getters for rgb values
	unsigned char r() const;
	unsigned char g() const;
	unsigned char b() const;

	// non-constant reference getters for rgb values
	unsigned char &r();
	unsigned char &g();
	unsigned char &b();

	// assignment operator
	Pixel &operator=(const Pixel &obj);

	// ostream operator
	friend ostream &operator<<(ostream &out, const Pixel &obj);

	void setVal(int avg) {
		this->R = avg;
		this->G = avg;
		this->B = avg;
	}

};


#endif