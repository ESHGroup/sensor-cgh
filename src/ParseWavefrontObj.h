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
* ParseWavefrontObj.h
*
* Created on: Jun 7, 2013
* Last Modified Jun 16, 2013
* Author: Richard McIntosh
* Email: rmcintosh@nmhu.edu
*
 */

#ifndef PARSEWAVEFRONTOBJ_H_
#define PARSEWAVEFRONTOBJ_H_

using namespace std;

#include <fstream>
#include <list>
#include <string>

#include <XnCppWrapper.h>
using namespace xn;

class WaveFrontObjFile {

private:

	list<XnPoint3D> * m_PointsLst;
	string m_FilePath;

	list<XnPoint3D> parseVectors(ifstream *);
	list<XnPoint3D> parseFaces(ifstream *);

public:

	static const char SYM_VECTOR   = 'v';
	static const char SYM_COMMENT  = '#';
	static const char SYM_FACE     = 'f';

	WaveFrontObjFile();

	list<XnPoint3D> * Parse(string);

	virtual ~WaveFrontObjFile();
};

#endif /* PARSEWAVEFRONTOBJ_H_ */
