/*
 * Screen.cpp
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#include "Screen.h"

using namespace std;
namespace pierre {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
}

bool Screen::init() {
	bool exitStat = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed" << endl;
		exitStat = false;
	}
	cout << "SDL_init succeeded" << endl;

	string temp = "Particle fire explosion";
	const char* windowName = temp.c_str();

	m_window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE); //test with 0 for last param

	if (m_window == NULL) {
		cout << "Could not create window: " << SDL_GetError() << endl;
		SDL_Quit();
		exitStat = false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();

		exitStat = false;
	}
	if (m_texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();

		exitStat = false;
	}

	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	//buffer init
	//memset(buffer, color, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_buffer[i] = 0x000000FF;
	}

	// initializing the screen to a uniform color

	return exitStat;
}

bool Screen::processEvent() {
	SDL_Event event;
	bool exitStatus = true;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			exitStatus = false;
			break;
		case SDL_WINDOWEVENT_RESIZED:
			//SDL_GetWindowSize(window,windowW,windowH);
			break;
		case SDL_MOUSEMOTION:
			std::cout << event.motion.x << std::endl;
			break;
		case SDL_MOUSEBUTTONDOWN:

			break;
		default:
			break;
		}
	}
	return exitStatus;
}

void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if (x < 0 || y < 0 || x > SCREEN_WIDTH-1 || y > SCREEN_HEIGHT-1) {
		return;
	}
	Uint32 color;
	Uint8 alpha = 0xff;
	color = red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += alpha;

	m_buffer[y * SCREEN_WIDTH + x] = color;

}

void Screen::clear(){
	memset(m_buffer,0,SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::close() {
	std::cout << "end of programm" << std::endl;
	delete[] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace pierre */
