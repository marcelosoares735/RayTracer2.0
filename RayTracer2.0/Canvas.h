#pragma once
#include "SDL.h"
#include "Color.h"

class Canvas {

public:
	int width;
	int height;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;

	Canvas(int width, int height): width(width), height(height), m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) { }
	
	bool init();
	bool processEvents();
	void close();
	void update();
	void setPixel(int x, int y, Color color);
	void clearScreen();
	//void render(Camera camera, World* world);
	
};