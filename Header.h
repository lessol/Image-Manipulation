/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

// libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifndef HEADER_H
#define HEADER_H

class Header{
private:
	string MAGIC;
	int W, H, MAX;
public:
	Header(); // constructor

	Header(string magic, int w, int h, int max); // parametrized constructor

	Header(Header const &obj); // Header copy constructor

	~Header(); // destructor

	// getters 
	int width() const; 
	int height() const;
	int max_color() const;
	string ppmType() const;

	// non-const reference getters
	int& width(); 
	int& height();
	int& max_color();
	string& ppmType();

	// assignment operator
	Header &operator=(Header const &obj);

	// ostream operator
	friend ostream &operator<<(ostream &out,const Header &obj);


};

#endif