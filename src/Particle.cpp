/*
 * Particle.cpp
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#include "Particle.h"

namespace pierre {

Particle::Particle() {
	m_x = 2.0*rand() / RAND_MAX - 1.0;
	m_y = 2.0*rand() / RAND_MAX  - 1.0;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(){
	m_x += 0.001*(2.0*rand() / RAND_MAX  -1.0);
	m_y += 0.001*(2.0*rand() / RAND_MAX  -1.0);

	if (m_x>1||m_x<-1){
		m_x = rand() / (double)RAND_MAX * 2.0 - 1.0;
	}
	if (m_y>1||m_y<-1){
		m_y = rand() / (double)RAND_MAX * 2.0 - 1.0;
		}

}


} /* namespace pierre */
