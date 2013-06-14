/*
 *  main.cpp
 *
 *  Created on: Jun 5, 2013
 *  Last Modified: Jun 13, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
 */

using namespace std;

#include <CImg.h>
using namespace cimg_library;


#include <complex>
#include <iostream>

#include <XnCppWrapper.h>
using namespace xn;

#include "HoloFilm.h"
#include "ParseWavefrontObj.h"
#include "DepthCapture.h"


int main(int argc, char** argv) {

	DepthCapture dc = DepthCapture("/opt/ComplexHologram/Debug/config.xml");

}
