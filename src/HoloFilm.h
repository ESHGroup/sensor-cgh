/*
 * HoloFilm.h
 *
 *  	Created On: May 27, 2013
 *  	Last Modified Jun 13, 2013
 *      Author: Richard McIntosh
 *      Email: rmcintosh@nmhu.edu
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

	static const double DPI = 600;
	static const double WAVE_LENGTH = 630e-9;
	static const double SAMPLING = 0.0254 / 600;
	static const int HOLO_FILM_ROW = 600;
	static const int HOLO_FILM_COL = 600;

	HoloFilm(int,int);

	complex<XnFloat> ** GetInterferencePattern(XnPoint3D *, int);

	virtual ~HoloFilm();

	inline XnFloat* getIpx(){return m_ipx;}

	inline XnFloat* getIpy(){return m_ipy;}

	complex<XnFloat> GetPointVal(int, int);
	void SetPointVal(int, int, complex<XnFloat>*);

};

#endif /* HOLOFILM_H_ */
