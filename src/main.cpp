/*
 *  main.cpp
 *
 *  Created on: Jun 5, 2013
 *  Last Modified: Jun 14, 2013
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

	/*	complex<XnFloat> ** if_pattern;

	 int dpi = 600;

	 HoloFilm * film = new HoloFilm(dpi, dpi);

	 if_pattern = film->GetInterferencePattern(&real_world_pts[0], XRes * YRes);


	 clog << "[DEBUG]: got interference pattern [OK]" << endl;

	 CImg<char> if_pattern_real(dpi, dpi);

	 char * curr_pix = 0;

	 curr_pix = &if_pattern_real.front();

	 for (int row = 0; row < dpi; row++) {
	 for (int col = 0; col < dpi; col++, curr_pix++) {

	 #ifdef _ESH_DEBUG_PEDANTIC
	 cout << "[DEBUG]: processing row [ " << row << "] column [" << col << "] [OK]" << endl;
	 #endif
	 if (*curr_pix >= 0) {
	 *curr_pix = ceil(if_pattern[row][col].real());
	 } else {
	 *curr_pix = 0;
	 }
	 }
	 }

	 if_pattern_real.display("Interference Pattern");
	 if_pattern_real.save("/home/rich/Desktop/if_test.png");
	 */
	
}

