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
	m_direction = 2.0 * M_PI * rand() / RAND_MAX;
	m_speed = 0.05*rand()/RAND_MAX;
	m_speed *= m_speed;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {
	double xspeed=m_speed*cos(m_direction);
	double yspeed= m_speed*sin(m_direction);

	m_x += xspeed*interval;
	m_y += yspeed*interval;
	m_direction+=0.0002*interval;

	if (m_x<-1||m_x>1||m_y<-1||m_y>1){
		m_x=0;
		m_y=0;
		m_direction = 2.0 * M_PI * rand() / RAND_MAX;
		m_speed = 0.0001*rand()/RAND_MAX;
	}

}

} /* namespace pierre */
