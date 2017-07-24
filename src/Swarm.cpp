/*
 * Swarm.cpp
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#include "Swarm.h"

namespace pierre {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

const Particle* const Swarm::getParticle() {
	return m_pParticles;
}

void Swarm::update() {
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update();
	}
}

} /* namespace pierre */
