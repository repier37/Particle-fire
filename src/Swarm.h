/*
 * Swarm.h
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"


namespace pierre {

class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle*  m_pParticles;
	int lastTime;

public:
	Swarm();
	const Particle* const getParticle();
	void update(int timeLoop);
	virtual ~Swarm();
};

} /* namespace pierre */

#endif /* SWARM_H_ */
