/*
 * Particle.h
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <stdlib.h>

namespace pierre {

class Particle {
public:
	double m_x;
	double m_y;


public:
	Particle();
	int getX();
	int getY();
	void update();
	virtual ~Particle();


public:
};

} /* namespace pierre */

#endif /* PARTICLE_H_ */
