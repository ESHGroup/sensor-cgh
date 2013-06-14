/*
 * DepthCapture.h
 *
 *  Created on: Jun 10, 2013
 *  Last Modified: Jun 13, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
 */

#ifndef DEPTHCAPTURE_H_
#define DEPTHCAPTURE_H_

#include <XnCppWrapper.h>
#include <XnCodecIDs.h>

using namespace xn;

class DepthCapture {

private:

	// sensor input device context
	Context m_DevContext;

	// depth format parameters
	Codec m_DepthFormat;

	// create device object
	Device m_Device;

	// depth stream
	DepthGenerator m_Depth;

	XnStatus writeMapToFile(const XnChar *, XnPoint3D *, int);

public:
	DepthCapture(const XnChar * strFileName);


	virtual ~DepthCapture();
};

#endif /* DEPTHCAPTURE_H_ */
