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
 *  HoloFilm.cpp
 *  Created on: May 27, 2013
 *  Last Modified: Jun 16, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
 */

#include <XnCppWrapper.h>
using namespace xn;

using namespace std;

#include <cmath>
#include <complex>
#include <iostream>
#include <list>

#include <assert.h>

#include "HoloFilm.h"

#define _USE_MATH_DEFINES

HoloFilm::HoloFilm(int num_rows, int num_cols) {

	// set dimensions of our HoloFilm
	m_num_rows = num_rows;
	m_num_cols = num_cols;

	scaleDims();

	int arr_size = ceil((2.0 * m_range) / SAMPLING);

	assert(arr_size > 0);

	m_ipy = new XnFloat[arr_size];
	m_ipx = new XnFloat[arr_size];

	resetHoloFilm(num_rows, num_cols);

	init_Ipx_Ipy();

}

complex<XnFloat> ** HoloFilm::GetInterferencePattern(XnPoint3D * obj_pts, int obj_count) {

	resetHoloFilm(m_num_rows, m_num_cols);

	int ip_size = floor((2.0 * m_range) / SAMPLING);

	XnFloat dx, dy, dz, distance = 0.0f;

	complex<XnFloat> complexwave = complex<XnFloat>(0.0, 0.0);

	int if_row, if_col;

	int percent_done = 0;
	int obj_count_off = obj_count / 100;

	for(int index=0; index < obj_count; index++) {

		// print out percent done for debugging ...
		if(index % obj_count_off == 0) {
			percent_done++;
			cout << "[DEBUG]: Interference pattern " << percent_done << " % generated ..." << endl;
		}

		for (if_row=0; if_row < ip_size; if_row++) {
			for (if_col=0 ; if_col < ip_size; if_col++) {

				dx = obj_pts[index].X - m_ipx[if_row];
				dy = obj_pts[index].Y - m_ipy[if_col];
				dz = obj_pts[index].Z - 0.0f;

				distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));

				complexwave = complex<XnFloat>(
						cos((2.0f * M_PI * distance) / WAVE_LENGTH),
						sin((2.0f * M_PI * distance) / WAVE_LENGTH));

				SetPointVal(if_row, if_col, new complex<XnFloat>((GetPointVal(if_row,if_col) + complexwave)));

			}
		}
	}


	clog << "[DEBUG]: generated interference pattern [OK]" << endl;


	return m_Points;
}

complex<XnFloat> HoloFilm::GetPointVal(int row, int col) {

	return m_Points[row][col];

}

void HoloFilm::resetHoloFilm(int num_rows, int num_cols) {

	m_Points = 0;

	m_Points = new complex<XnFloat> * [num_rows];

	for (int row = 0; row < num_rows; row++) {

		m_Points[row] = new complex<XnFloat>[num_cols];

		for (int col = 0; col < num_cols; col++) {

			m_Points[row][col] = complex<XnFloat>(0.0, 0.0);

		}
	}
}

void HoloFilm::init_Ipx_Ipy() {

	// initialize the m_ipx and m_ipy arrays
	double curr_val = -1 * m_range;

	for (int i = 0; curr_val <= m_range; curr_val += SAMPLING, i++) {

		m_ipx[i] = curr_val;
		m_ipy[i] = curr_val;
	}

}

void HoloFilm::scaleDims() {

	// set our physical hologram dimensions we'll print to
	m_holo_dims = 1;


	// calculate upper bound of range to scale to
	m_range = m_holo_dims * 0.0254 / 2.0;

}

void HoloFilm::SetPointVal(int row, int col, complex<XnFloat>* val) {

	m_Points[row][col] = *val;

}

HoloFilm::~HoloFilm() {

}

