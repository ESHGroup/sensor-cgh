/*
 * ParseWavefrontObj.cpp
 *
 *  Created on: Jun 7, 2013
 *  Last Modified Jun 13, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
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

		cout << line << endl;

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

		cout << "x = " <<  pt.X << " y = " << pt.Y << " z = " << pt.Z << endl;

	}

	return pts_lst;
}

WaveFrontObjFile::~WaveFrontObjFile() {
	delete(m_PointsLst);
}

