/*
 * CPointSource_test.cpp
 *
 *  Created on: May 27, 2013
 *      Author: root
 */
using namespace std;

#include "PointSource.h"
#include <iostream>
#include <cassert>


/*
int main() {


	int numPoints = 100;

	PointSource ** objPoints = new PointSource * [numPoints];


	for(int i=0; i < numPoints; i++) {
			objPoints[i] = new PointSource(double(i), double(i+1), double(i-1), double(1), double(i));
	}

	for(int i=0; i < numPoints; i++) {

		cout << "objPoints[" << i << "].x = " << objPoints[i]->getX() << endl;
		cout << "objPoints[" << i << "].y = " << objPoints[i]->getY() << endl;
		cout << "objPoints[" << i << "].z = " << objPoints[i]->getZ() << endl;
		cout << "objPoints[" << i << "].w = " << objPoints[i]->getW() << endl;

		assert(objPoints[i]->getX() == double(i));
		assert(objPoints[i]->getY() == double(i+1));
		assert(objPoints[i]->getZ() == double(i-1));
		assert(objPoints[i]->getVal() == double(i));

		cout << "objPoints[" << i << "] TEST PASSED!" << endl;

	}

	PointSource pt  = PointSource(1.0, 0.0, -1.0, 1.0, 5.0);

	cout << pt.toString() << endl;

	assert(pt.getX() == 1.0);
	cout << "pt x = " << pt.getX() << ": test PASSED!" << endl;


	assert(pt.getY() == 0.0);
    cout << "pt y = " << pt.getY() << ": test PASSED!" << endl;

    assert(pt.getZ() == -1.0);
    cout << "pt z = " << pt.getZ() << ": test PASSED!" << endl;

    assert(pt.getW() == 1.0);
    cout << "pt w = " << pt.getW() << ": test PASSED!" <<  endl;

    return 0;
}*/

