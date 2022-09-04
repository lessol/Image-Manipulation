/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#include "Header.h"
#include <iostream>
#include <string>
using namespace std;

/*************************************************************
 *                 Default Header Constructor                *
 * Passed   : None             								 *
 * Purpose  : Assign default values to Header private members*
  ************************************************************/
Header::Header() {
	MAGIC = "";
	W = 0;
	H = 0;
	MAX = 0;
}

/*************************************************************
 *                Header Parametrized Constructor            *
 * Passed   : string parameter and 3 integer parameters      *
 * Purpose  : Assign user passed values to Header members    *
  ************************************************************/
Header::Header(string magic, int w, int h, int max) {
	this->MAGIC = magic;
	this->W = w;
	this->H = h;
	this->MAX = max;
}

/*************************************************************
 *                Header Copy Constructor                    *
 * Passed   : Header object                                  *
 * Purpose  : Assign Header obj values to calling obj members*
  ************************************************************/
Header::Header(Header const &obj) {
	this->MAGIC = obj.MAGIC;
	this->W = obj.W;
	this->H = obj.H;
	this->MAX = obj.MAX;
}


/*************************************************************
 *                      destructor     						 *
 * Purpose  : destroy Header objects		    	 		 *
  ************************************************************/
Header::~Header(){
	
}

/*************************************************************
 *                getters for Header members                 *
 * Purpose  : get member values from Header objects		     *
  ************************************************************/
int Header::width() const {return this->W;} 
int Header::height() const {return this->H;} 
int Header::max_color() const {return this->MAX;} 
string Header::ppmType() const {return this->MAGIC;} 

// non constant reference getters
int& Header::width()  {return this->W;} 
int& Header::height() {return this->H;} 
int& Header::max_color() {return this->MAX;} 
string& Header::ppmType() {return this->MAGIC;} 

/*************************************************************
 *                Header assignment operator                 *
 * Passed   : Address of Header object             			 *
 * Purpose  : Assign Header obj members to other header obj  *
  ************************************************************/
Header& Header::operator=(Header const &obj) {

	if (this == &obj)
		return *this;
	
	this->MAGIC = obj.MAGIC;
	this->W = obj.W;
	this->H = obj.H;
	this->MAX = obj.MAX;

	return *this;
}


/*************************************************************
 *                Header ostream operator                  	 *
 * Purpose  : Output stream objects		    		   		 *
  ************************************************************/
ostream &operator<<(ostream &out, Header const &obj) {
	out<<obj.ppmType()<<endl<<obj.width()<<endl<<obj.height()<<endl<<obj.max_color()<<endl;

	return out;
}

