/*
 * Particle.cpp
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#include "Particle.h"
#include <math.h>

namespace pierre {

Particle::Particle() :
	m_x(0), m_y(0) {
	m_direction = M_PI*2.0*(1.0 * rand() / RAND_MAX) -3*M_PI/4.0 ;
	m_speed = 0.0002 * rand() / RAND_MAX;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {

	m_direction = fmod((m_direction+0.0002 * interval),2*M_PI);

	if (m_x <= -0.99) {
		m_direction = M_PI / 2 * (2.0 * rand() / RAND_MAX - 1);
	} else if (m_x >= 0.99) {
		m_direction = M_PI * (1.0 * rand() / RAND_MAX) + M_PI / 2;
	}
	if (m_y <= -0.9) {
		m_direction = M_PI * (1.0 * rand() / RAND_MAX); // * (1.0 * rand() / RAND_MAX);
	} else if (m_y >= 0.9) {
		m_direction = -M_PI * (1.0 * rand() / RAND_MAX);
	}
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);
	m_speed +=0.0000002;

	if (m_speed >0.0002){
		m_speed=m_speed = 0.01 * rand() / RAND_MAX;
	}

	m_x += xspeed * interval;
	m_y += yspeed * interval;
	/*
	 m_x=0;
	 m_y=0;
	 m_direction = 2.0 * M_PI * rand() / RAND_MAX;
	 m_speed = 0.0001*rand()/RAND_MAX;
	 }*/

}

} /* namespace pierre */
