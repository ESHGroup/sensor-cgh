
using namespace std;

#ifndef CPOINTSOURCE_H_
#define CPOINTSOURCE_H_

#include <string>

class PointSource {

protected:

	double m_x,m_y,m_z,m_w;
	double m_val;

public:

	PointSource();
	PointSource(double, double, double, double, double);

	string toString();

	virtual ~PointSource();

	double getW() const {
		return m_w;
	}

	double getX() const {
		return m_x;
	}

	double getY() const {
		return m_y;
	}

	double getZ() const {

		return m_z;
	}

	double getVal() const {
		return m_val;
	}
};

#endif /* CPOINTSOURCE_H_ */
