/*
 * SDLTest.cpp
 *
 *  Created on: 20 juil. 2017
 *      Author: root
 */

#include <iostream>
#include <SDL.h>
using namespace std;

int main() {

	const int SCREEN_HEIGHT = 600;
	const int SCREEN_WIDTH = 800;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed" << endl;
		return 1;
	}
	cout << "SDL_init succeeded" << endl;

	string temp = "Particle fire explosion";
	const char* windowName = temp.c_str();
	SDL_Window* window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE); //test with 0 for last param

	if (window == NULL) {
		cout << "Could not create window: " << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	bool quit = false;

	SDL_Event event;

	SDL_Renderer* renderer;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	int r = 0;
	int g = 0;
	int b = 0;

	while (!quit) {
		SDL_SetRenderDrawColor(renderer,r, g, b, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		//update the positions of the particles
		// draw the particles
		//check for messages/events
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				//SDL_GetWindowSize(window,windowW,windowH);
				break;
			case SDL_MOUSEMOTION:

				r=(r+event.motion.xrel)%255;
				g=(g+event.motion.yrel)%255;
				cout<<"R is:"<<r<<" g is: "<<g<<endl;
			default:
				break;
			}
		}

	}
	cout<<"end of programm"<<endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

