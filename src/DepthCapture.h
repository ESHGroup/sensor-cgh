/*
 *  DepthCapture.h
 *
 *  Created on: Jun 10, 2013
 *  Last Modified: Jun 14, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
 */

#ifndef DEPTHCAPTURE_H_
#define DEPTHCAPTURE_H_

#include <XnCppWrapper.h>
#include <XnCodecIDs.h>

using namespace xn;

#include <iostream>

using namespace std;

class DepthCapture {

private:

	// sensor input device context
	Context m_DevContext;

	// create device object
	Device m_Device;

	// depth stream
	DepthGenerator m_Depth;

	// depth map's meta-data
	DepthMetaData m_MapMD;

	// OpenNI configuration file
	const XnChar * m_ConfigFile;

	ostream& m_DepthStream;

	// maximum amount of depth frames to capture
	XnUInt64 m_MaxFrames;

	// our sensor's depth map resolutions
	XnUInt32 m_XRes;
	XnUInt32 m_YRes;

	XnStatus writeDepthToStream(ostream&, XnPoint3D *, int, XnUInt64);
	XnStatus initDevice(const XnChar *);
	XnStatus initPoints(XnPoint3D *);

public:

	DepthCapture(const XnChar *, ostream&);
	XnStatus Capture(ostream&, XnUInt32);

	virtual ~DepthCapture();
};

#endif /* DEPTHCAPTURE_H_ */

