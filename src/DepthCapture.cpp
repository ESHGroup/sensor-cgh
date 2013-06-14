/*
 *  DepthCapture.cpp
 *
 *  Created on: Jun 10, 2013
 *  Last Modified: Jun 14, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
 *
 */

#include <CImg.h>
using namespace cimg_library;

#include <XnCppWrapper.h>

#include "DepthCapture.h"
#include "HoloFilm.h"

using namespace std;

#include <iostream>
#include <fstream>

DepthCapture::DepthCapture(const XnChar * strConfigFile, ostream& depthStream) {

	XnStatus ret = XN_STATUS_OK;

	ret = initDevice(strConfigFile);

	if (!(ret == XN_STATUS_OK)) {
		cerr << "[FATAL]: Device initialization [FAILED]" << endl;
	}

	m_DepthStream = depthStream;
}

XnStatus DepthCapture::initDevice(const XnChar * strConfigFile) {

	XnStatus ret = XN_STATUS_OK;

	ScriptNode sn = ScriptNode();
	EnumerationErrors errs;

	// initialize our device settings from xml config file
	ret = m_DevContext.InitFromXmlFile(strConfigFile, sn, &errs);

	if (ret != XN_STATUS_OK ) {

		cerr << "[FATAL]: Device context initialization [FAILED]" << endl;
		return XN_STATUS_ERROR;
	}

	clog << "[INFO]: Creating depth stream [...]" << endl;

	ret = m_Depth.Create(m_DevContext);

	if (ret != XN_STATUS_OK ) {

		cerr << "[FATAL]: DepthGenerator node creation [FAILED]" << endl;
		return XN_STATUS_ERROR;
	}

	// get the meta-data for the depth map
	m_Depth.GetMetaData(m_MapMD);

	// get our sensor's depth map resolution
	m_XRes = m_MapMD.XRes();
	m_YRes = m_MapMD.YRes();

	return XN_STATUS_OK;
}

XnStatus DepthCapture::Capture(ostream& outStream, XnUInt32 numFrames) {

	XnStatus ret = XN_STATUS_OK;

	// holds all projected points in the map
	XnPoint3D proj_pts[m_XRes * m_YRes];

	// will be populated with real world points mapped from projected points
	XnPoint3D real_world_pts[m_XRes * m_YRes];

	ret = m_DevContext.StartGeneratingAll();

	if (ret != XN_STATUS_OK ) {

		cerr << "[FATAL]: Depth generating [FAILED]" << endl;
		return XN_STATUS_ERROR;
	}

	const XnDepthPixel* pDepth;
	bool bCapture = true;

	while (m_DevContext.WaitOneUpdateAll(m_Depth) == XN_STATUS_OK && bCapture) {

		// initialize points in arrays back to origin(0,0,0)
		initPoints(&proj_pts[0]);
		initPoints(&real_world_pts[0]);

		// update our data for each frame
		m_Depth.GetMetaData(m_MapMD);

		pDepth = m_MapMD.Data();

	    	for (int row = 0; row < (int) m_YRes; row++) {
			for (int col = 0; col < (int) m_XRes; col++) {

				int index = (m_XRes * row) + col;

				proj_pts[index].X = row;
				proj_pts[index].Y = col;
				proj_pts[index].Z = *pDepth;

				++pDepth;
			}
		}

		ret = m_Depth.ConvertProjectiveToRealWorld((m_XRes * m_YRes), &proj_pts[0], &real_world_pts[0]);

		if (ret != XN_STATUS_OK ) {

			cerr << "[FATAL]: Conversion of projective points to real-world points [FAILED]" << endl;
		}

		writeDepthToStream(m_DepthStream, real_world_pts, (m_XRes * m_YRes), m_MapMD.Timestamp());
	}
	return XN_STATUS_OK;
}


XnStatus DepthCapture::writeDepthToStream(ostream& depthStream, XnPoint3D * pDepthMap, int numPoints, XnUInt64 timestamp) {

	depthStream << "# DEPTH FRAME: [" << timestamp << "]" << endl;

	for (int i = 0; i < numPoints; i++) {

		// write vertex to stream
		depthStream << "v " << (float)pDepthMap->X << " " << (float)pDepthMap->Y << " " << (float)pDepthMap->Z << " " << 1.0f <<  endl;

		pDepthMap++;
	}

	clog << "[INFO]: Wrote vertices to file [OK]" << endl;

	return XN_STATUS_OK ;
}

XnStatus DepthCapture::initPoints(XnPoint3D * pPoints) {

	XnPoint3D origin;

	origin.X = (XnFloat) 0.0f;
	origin.Y = (XnFloat) 0.0f;
	origin.Z = (XnFloat) 0.0f;

	for (int i = 0; i < (int) (m_XRes * m_YRes); i++) {
		*pPoints = origin;
	}

	return XN_STATUS_OK;
}


DepthCapture::~DepthCapture() {

	// release our device nicely
	m_DevContext.Release();

}


