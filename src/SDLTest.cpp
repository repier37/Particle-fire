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
	srand(time(NULL));
	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	bool quit = false;
	Swarm swarm;
	const Particle* pParticle = swarm.getParticle();

	while (!quit) {

		//update the positions of the particles

		swarm.update();

		// draw the particles
		screen.clear();
		int elapsed = SDL_GetTicks();

		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0004)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0006)) * 128;

		/*
		 for (int x = 0; x < screen.SCREEN_WIDTH;
		 x++) {
		 for (int y = 0;
		 y < screen.SCREEN_HEIGHT; y++) {
		 screen.setPixel(x, y, red, green, blue);
		 }
		 }*/

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			screen.setPixel((pParticle[i].m_x + 1) * Screen::SCREEN_WIDTH / 2,
					(pParticle[i].m_y + 1) * Screen::SCREEN_HEIGHT / 2, red,
					green, blue);
		}

		screen.update();


		//check for messages/events
		if (screen.processEvent() == false) {
			break;
		}

	}
	screen.close();

	return 0;
}

