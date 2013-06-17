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
*
* HoloFilm.h
*
* Created On: May 27, 2013
* Last Modified Jun 16, 2013
* Author: Richard McIntosh
* Email: rmcintosh@nmhu.edu
*
*/

#ifndef HOLOFILM_H_
#define HOLOFILM_H_

#include <XnCppWrapper.h>
using namespace xn;

#include <complex>
#include <list>
using namespace std;

class HoloFilm {

protected:

    	// HoloFilm number of rows
    	int m_num_rows;

    	// HoloFilm number of columns
    	int m_num_cols;
	
    	// will hold rows x columns array of complex Point Sources
    	complex<XnFloat> ** m_Points;

    	// dimensions of hologram in inches^2
    	int m_holo_dims;

    	// range we start/stop -range -> +range
    	double m_range;

    	// interference pattern x
    	XnFloat * m_ipx;

    	// interference pattern y
    	XnFloat * m_ipy;

    	void resetHoloFilm(int, int);
    	void init_Ipx_Ipy();
  	void scaleDims();

public:

	static const double DPI          = 600;
	static const double WAVE_LENGTH  = 630e-9;
	static const double SAMPLING     = 0.0254 / 600;
	static const int HOLO_FILM_ROW   = 600;
	static const int HOLO_FILM_COL   = 600;

	HoloFilm(int,int);

	complex<XnFloat> ** GetInterferencePattern(XnPoint3D *, int);

	virtual ~HoloFilm();

	inline XnFloat* getIpx(){return m_ipx;}

	inline XnFloat* getIpy(){return m_ipy;}

	complex<XnFloat> GetPointVal(int, int);
	void SetPointVal(int, int, complex<XnFloat>*);

};

#endif /* HOLOFILM_H_ */
