/*
 * Screen.h
 *
 *  Created on: 23 juil. 2017
 *      Author: root
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL.h>
#include <iostream>

namespace pierre {

class Screen {
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;


public:
	const static int SCREEN_HEIGHT = 600;
	const static int SCREEN_WIDTH = 800;
	Uint32* m_buffer;
	Uint32* m_buffer2;

public:
	Screen();
	bool init();
	bool processEvent();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();
	void blurPixel(int x, int y);
	void blur();
	void close();

};

} /* namespace pierre */

#endif /* SCREEN_H_ */
