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
	SDL_Texture* texture;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();

		return 3;
	}
	if (texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();

		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	Uint32 color = 0xFF;
	//buffer init
	memset(buffer, color, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	/*for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = 0xFFFFFFFF;
	}*/

	SDL_Rect updateRect;
	updateRect.x = 0;
	updateRect.y = 0;
	updateRect.w = SCREEN_WIDTH;
	updateRect.h = SCREEN_HEIGHT;
	SDL_UpdateTexture(texture, &updateRect, buffer,
			updateRect.w * sizeof(Uint32));

	while (!quit) {
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		/*SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		 SDL_RenderClear(renderer);
		 SDL_RenderPresent(renderer);*/
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
				break;
			case SDL_MOUSEBUTTONDOWN:
				buffer[(event.button.y)*SCREEN_WIDTH+event.button.x]= 0x55;
				SDL_UpdateTexture(texture, &updateRect, buffer,
							updateRect.w * sizeof(Uint32));
				cout<<event.button.x<<endl;
				cout <<event.button.y<<endl;
			break;
			default:
				break;
			}
		}

	}
	cout << "end of programm" << endl;
	delete[] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

