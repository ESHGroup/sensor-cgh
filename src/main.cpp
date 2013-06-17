/* Copyright (C) 2013 ESHGroup
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* main.cpp
*
* Created on: Jun 5, 2013
* Last Modified: Jun 16, 2013
* Author: Richard McIntosh
* Email: rmcintosh@nmhu.edu
*
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

