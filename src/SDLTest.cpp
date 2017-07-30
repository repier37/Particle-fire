/*
 * SDLTest.cpp
 *
 *  Created on: 20 juil. 2017
 *      Author: root
 */

#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

using namespace pierre;
using namespace std;

int main() {
	int count = 0;
	srand(time(NULL));
	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	bool quit = false;
	Swarm swarm;
	const Particle* pParticle = swarm.getParticle();

	while (!quit) {
		int elapsed = SDL_GetTicks();
		//update the positions of the particles

		swarm.update(elapsed);

		// draw the particles

		//screen.clear();



		unsigned char green = (1 + sin(elapsed * 0.0002)) * 102+50;
		unsigned char red = (1 + sin(elapsed * 0.0004)) * 102+50;
		unsigned char blue = (1 + sin(elapsed * 0.0006)) * 102+50;



		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticle[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 +Screen::SCREEN_HEIGHT/2;
			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		screen.update();
		count++;


		//cout << count << endl;

		//check for messages/events
		if (screen.processEvent() == false) {
			break;
		}

	}
	screen.close();

	return 0;
}

