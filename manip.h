/*
 * Name: Sol Lesesne
 * C++ ppm image manipulations(greenscreen,grayscale,mirror)
 * */

#ifndef MANIP_H
#define MANIP_H

// libraries
#include "Image.h"
#include "Header.h"
#include "Pixel.h"
#include <iostream>
#include <string>
#include <vector>

// function prototypes
void gray_scale(Image &grayImg); 
void mirror(Image &mirrorImg);
void green_screen(Image &img, Image &original);


#endif