/*
 * HologramRayCasting.h
 *
 *  Created on: Jun 4, 2013
 *      Author: student
 */



#ifndef HOLOGRAMRAYCASTING_H_
#define HOLOGRAMRAYCASTING_H_

#include "PointSource.h"


class HologramRayCasting {

private:


public:

	HologramRayCasting();
	HologramRayCasting(PointSource*, double*, double* );

	virtual ~HologramRayCasting();
};

#endif /* HOLOGRAMRAYCASTING_H_ */
