/*
 * Swarm.cpp
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#include "Swarm.h"

namespace pierre {

Swarm::Swarm(): lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

const Particle* const Swarm::getParticle() {
	return m_pParticles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed -lastTime;
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}
	lastTime=elapsed;
}

} /* namespace pierre */
