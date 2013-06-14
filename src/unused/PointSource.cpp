/*
 * PointSource.cpp
 * Date Created: May 27, 2013
 * Author: Richard McIntosh
 * TODO: Make PointSource generic instead of only storing
 *       double values.
 */


using namespace std;

#include <string>
#include <iostream>
#include <stdio.h>


#include "PointSource.h"


PointSource::PointSource() {

	// Default to origin for default constructor

	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;
	m_w = 0.0;

	m_val = 0.0;

}

PointSource::PointSource(double x, double y, double z, double w, double val) {

	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;

	m_val = val;
}

string PointSource::toString() {

	char buff[100];

	sprintf(buff, "x = %f y = %f z = %f w = %f value = %f", m_x, m_y, m_z, m_w, m_val);
	return buff;

}


PointSource::~PointSource() {

}

