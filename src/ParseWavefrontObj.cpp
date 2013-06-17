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

* ParseWavefrontObj.cpp
*
* Created on: Jun 7, 2013
* Last Modified Jun 16, 2013
* Author: Richard McIntosh
* Email: rmcintosh@nmhu.edu
*
 */

#define __DEBUG

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>

#include "ParseWavefrontObj.h"

WaveFrontObjFile::WaveFrontObjFile() {

	m_PointsLst = new list<XnPoint3D>();
	m_FilePath = "";

}

list<XnPoint3D> * WaveFrontObjFile::Parse(string FilePath) {

	ifstream f_stream(FilePath.c_str());

	list<XnPoint3D> * pts_lst = new list<XnPoint3D>();
	list<XnPoint3D>::iterator itr;

	string line, type_token;

	XnFloat x = 0.0f;
	XnFloat y = 0.0f;
	XnFloat z = 0.0f;

	do {

		getline(f_stream, line);

		clog << line << endl;

		istringstream str_stream(line);

		str_stream >> type_token;

		if (type_token.compare("v") == 0) {

			str_stream >> x >> y >> z;

			XnPoint3D pt;

			pt.X = x;
			pt.Y = y;
			pt.Z = z;

			pts_lst->push_back(pt);

		}

	} while (!f_stream.eof());

	for(itr = pts_lst->begin(); itr != pts_lst->end(); ++itr) {

		XnPoint3D pt = (XnPoint3D)*itr;

		clog << "x = " <<  pt.X << " y = " << pt.Y << " z = " << pt.Z << endl;

	}

	return pts_lst;
}

WaveFrontObjFile::~WaveFrontObjFile() {
	delete(m_PointsLst);
}

