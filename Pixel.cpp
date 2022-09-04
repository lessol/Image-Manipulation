/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#include "Pixel.h"
#include <iostream>
using namespace std;

/*************************************************************
 *                    Pixel Constructor                      *
 * Passed   : None             								 *
 * Purpose  : Assign default values to Pixel private members *
  ************************************************************/
Pixel::Pixel() {
	R = 0;
	G = 0;
	B = 0;
}

/*************************************************************
 *                Pixel Parametrized Constructor             *
 * Passed   : Three unsinged chars             				 *
 * Purpose  : Assign user passed values to private rgb values*
  ************************************************************/
Pixel::Pixel(unsigned char x, unsigned char y, unsigned char z) {
	this->R = x;
	this->G = y;
	this->B = z;
}

/*************************************************************
 *                Pixel Copy Constructor                     *
 * Passed   : Pixel object             				 		 *
 * Purpose  : Assign Pixel obj values to private rgb values  *
  ************************************************************/
Pixel::Pixel(const Pixel &obj){
	this->R = obj.R;
	this->G = obj.G;
	this->B = obj.B;
}


/*************************************************************
 *                Pixel assignment operator                  *
 * Passed   : Address of Pixel object             			 *
 * Purpose  : Assign Pixel object members to other Pixel obj *
  ************************************************************/
Pixel& Pixel::operator=(const Pixel &obj){

	if (this == &obj)
		return *this;

	this->R = obj.R;
	this->G = obj.G;
	this->B = obj.B;

	return *this;
}


/*************************************************************
 *                Pixel ostream operator                  	 *
 * Purpose  : Output stream objects		    		   		 *
  ************************************************************/
ostream & operator<<(ostream &out, const Pixel &obj) {
	out<<obj.R<<" "<<obj.G<<" "<<obj.B;

	return out;
}

/*************************************************************
 *               const getters for rgb values                *
 * Purpose  : get rgb values from Pixel objects		    	 *
  ************************************************************/
unsigned char Pixel::r() const {return this->R;}
unsigned char Pixel::g() const {return this->G;}
unsigned char Pixel::b() const {return this->B;}


/*************************************************************
 *         non-constant reference getters for rgb values     *
 * Purpose  : get rgb values from Pixel objects		    	 *
  ************************************************************/
unsigned char& Pixel::r() {return this->R;}
unsigned char& Pixel::g() {return this->G;}
unsigned char& Pixel::b() {return this->B;}

/*************************************************************
 *                      destructor     						 *
 * Purpose  : destroy Pixel objects		    	 		     *
  ************************************************************/
Pixel::~Pixel() {
    
}

