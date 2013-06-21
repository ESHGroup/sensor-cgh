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
 *  DepthCapture.h
 *
 *  Created on: Jun 10, 2013
 *  Last Modified: Jun 16, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
 *
 */

#ifndef DEPTHCAPTURE_H_
#define DEPTHCAPTURE_H_

#include <XnCppWrapper.h>
#include <XnCodecIDs.h>

using namespace xn;

#include <iostream>
#include <fstream>

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

	// maximum amount of depth frames to capture
	XnUInt64 m_MaxFrames;

	// our sensor's depth map resolutions
	XnUInt32 m_XRes;
	XnUInt32 m_YRes;

	XnStatus writeDepthToStream(ostream&, XnPoint3D *, int, XnUInt64);
	XnStatus initDevice(const XnChar *);
	XnStatus initPoints(XnPoint3D *);

public:

	DepthCapture(const XnChar *);
	XnStatus Capture(ostream&, XnUInt32);

	virtual ~DepthCapture();
};

#endif /* DEPTHCAPTURE_H_ */

