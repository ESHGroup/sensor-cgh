/*
 * ParseWavefrontObj.h
 *
 *  Created on: Jun 7, 2013
 *  Last Modified Jun 13, 2013
 *  Author: Richard McIntosh
 *  Email: rmcintosh@nmhu.edu
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

	static const char SYM_VECTOR = 'v';
	static const char SYM_COMMENT = '#';
	static const char SYM_FACE = 'f';

	WaveFrontObjFile();

	list<XnPoint3D> * Parse(string);

	virtual ~WaveFrontObjFile();
};

#endif /* PARSEWAVEFRONTOBJ_H_ */
