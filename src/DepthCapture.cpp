/*
 * DepthCapture.cpp
 *
 *  Created on: Jun 10, 2013
 *  Last Modified: Jun 13, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
 *
 */

// NOTE: define for extended debugging - so ugly, but I'm not sure what
// logging system I want to use - plus this is probably just proto code

#ifndef _ESH_DEBUG
	#define _ESH_DEBUG
#endif

#include <CImg.h>
using namespace cimg_library;

#include <XnCppWrapper.h>

#include "DepthCapture.h"
#include "HoloFilm.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>

DepthCapture::DepthCapture(const XnChar * strFileName) {

	XnStatus ret = XN_STATUS_OK;

	ScriptNode sn = ScriptNode();

	EnumerationErrors errs;

	// initialize our device settings from xml config file
	ret = m_DevContext.InitFromXmlFile(strFileName, sn, &errs);

	if (ret != XN_STATUS_OK ) {

		cerr << "[FATAL]: Device context initialization [FAILED]" << endl;
		return;
	}

	#ifdef _ESH_DEBUG
		cout << "[DEBUG]: Creating depth stream [...]" << endl;
	#endif

	ret = m_Depth.Create(m_DevContext);

	if (ret != XN_STATUS_OK ) {

		cerr << "[FATAL]: DepthGenerator node creation [FAILED]" << endl;
		return;
	}

	#ifdef _ESH_DEBUG
		cout << "[DEBUG]: Depth generating started [OK]" << endl;
	#endif

	ret = m_DevContext.StartGeneratingAll();

	if (ret != XN_STATUS_OK ) {

		cerr << "[FATAL]: Depth generating [FAILED]" << endl;
		return;
	}

	DepthMetaData mapMD;

	// get the meta-data for the depth map
	m_Depth.GetMetaData(mapMD);

	// get our sensor's depth map resolution
	XnUInt32 XRes = mapMD.XRes();
	XnUInt32 YRes = mapMD.YRes();

	// holds all projected points in the map
	XnPoint3D proj_pts[XRes * YRes];

	// will be populated with real world points mapped from projected points
	XnPoint3D real_world_pts[XRes * YRes];

	XnPoint3D origin;

	origin.X = (XnFloat) 0.0f;
	origin.Y = (XnFloat) 0.0f;
	origin.Z = (XnFloat) 0.0f;

	for (int i = 0; i < (int) (XRes * YRes); i++) {

		proj_pts[i] = origin;
		real_world_pts[i] = origin;
	}

	int frames_cnt = 0;
	int MAX_FRAMES = 1;

	bool b_get_frames = true;

	while (m_DevContext.WaitOneUpdateAll(m_Depth) == XN_STATUS_OK && b_get_frames) {

		// update our data for each frame
		m_Depth.GetMetaData(mapMD);

		const XnDepthPixel* pDepth = mapMD.Data();

     	for (int row = 0; row < (int) YRes; row++) {
			for (int col = 0; col < (int) XRes; col++) {

				int index = (XRes * row) + col;

				proj_pts[index].X = row;
				proj_pts[index].Y = col;
				proj_pts[index].Z = *pDepth;

				#ifdef _ESH_DEBUG_PEDANTIC

				cout << "DEBUG: X = " << proj_pts[index].X << " Y = "
						<< proj_pts[index].Y << " Z = " << proj_pts[index].Z
				     	<< endl;
				#endif

				++pDepth;

			}
		}

		#ifdef _ESH_DEBUG
				cout << "[DEBUG]: Received depth frame [OK]" <<  endl;
		#endif
		ret = m_Depth.ConvertProjectiveToRealWorld((XRes * YRes), &proj_pts[0], &real_world_pts[0]);

		if (ret != XN_STATUS_OK ) {

			cerr << "[FATAL]: Conversion of projective points to real-world points [FAILED]" << endl;
		}

		// IF PATTERN TEST ----> REMOVE

		/*	complex<XnFloat> ** if_pattern;

			int dpi = 600;

			HoloFilm * film = new HoloFilm(dpi, dpi);

      		if_pattern = film->GetInterferencePattern(&real_world_pts[0], XRes * YRes);

		#ifdef _ESH_DEBUG
      			cout << "[DEBUG]: got interference pattern [OK]" << endl;
		#endif
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
			// END INTERFERENCE PATTERN TEST: REMOVE!




		writeMapToFile("/opt/ComplexHologram/Debug/frames2.obj", real_world_pts, (XRes * YRes));

		frames_cnt++;

		if(frames_cnt > MAX_FRAMES) {

			#ifdef _ESH_DEBUG
				cout << "[INFO]: Total depth frames written: " << (frames_cnt - 1) << endl;
			#endif

			b_get_frames = false;

		} else {

			#ifdef _ESH_DEBUG
				cout << "[DEBUG]: Frames written: " << frames_cnt << endl;
			#endif
		}
	}
	m_DevContext.Release();

}

XnStatus DepthCapture::writeMapToFile(const XnChar * strFileName,
		XnPoint3D * map, int cnt) {

	ofstream fp;

	fp.open(strFileName, (ios::out | ios::app));

	if (fp.is_open()) {


		fp << "# DEPTH FRAME: " << endl;
     	fp << "#######################################################" << endl << endl;

		for (int i = 0; i < cnt; i++) {

			// don't write null vertices to file
			// TODO: is this check more expensive then just processing these points?
			if(!(map->X == 0.0f && map->Y == 0.0f && map->Z == 0.0f)) {

				#ifdef _ESH_DEBUG
					fp << "# X = " << (i / 640) << " Y = " << (i % 640) << endl;
				#endif

				// write vertices to file
				fp << "v " << (float)map->X << " " << (float)map->Y << " " << (float)map->Z << " " << 1.0f <<  endl;
			}

			map++;
		}

		fp.close();

		return XN_STATUS_OK ;

	} else {

		return XN_STATUS_ERROR;
	}

}

DepthCapture::~DepthCapture() {

}

