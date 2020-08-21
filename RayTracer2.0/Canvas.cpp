#include "Canvas.h"
#include <iostream>
#include <algorithm>
#include <cassert>

bool Canvas::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL init failed." << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		std::cout << "Could not create window" << std::endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (m_renderer == NULL) {
		std::cout << "Could not create renderer" << std::endl;
		SDL_DestroyWindow(m_window);
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, width, height);

	if (m_texture == NULL) {
		std::cout << "Could not create texture" << std::endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		return false;
	}

	m_buffer = new Uint32[Uint32(width*height)];

	memset(m_buffer, 0, Uint32(width*height) * sizeof(Uint32));

	update();

	return true;
}

void Canvas::setPixel(int x, int y, Color color) {
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	
	Uint32 finalColor = 0;

	Uint8 r = std::clamp(Uint32(color.r * 255), Uint32(0), Uint32(255));
	Uint8 g = std::clamp(Uint32(color.g * 255), Uint32(0), Uint32(255));
	Uint8 b = std::clamp(Uint32(color.b * 255), Uint32(0), Uint32(255));
	finalColor += (r << 8 | g << 16 | b << 24 | 0xff );
	/*finalColor <<= 8;
	finalColor += green;
	finalColor <<= 8;
	finalColor += blue;
	finalColor <<= 8;
	finalColor += 0xff;*/

	m_buffer[(y * width) + x] = finalColor;

}

void Canvas::update() {
	// ReSharper disable once CppCStyleCast
	SDL_UpdateTexture(m_texture, NULL, m_buffer, width * (int)sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

bool Canvas::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			return false;
	}
	return true;
}

void Canvas::close() {
	delete[] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Canvas::clearScreen() {
	memset(m_buffer, 0, width * height * sizeof(Uint32));
}

//void Canvas::render(Camera camera, World * world) {
//	for (int y = 0; y < camera.vsize; y++) {
//		for (int x = 0; x < camera.hsize; x++) {
//			Ray ray;
//			ray.rayForPixel(camera, x, y);
//			Color color = colorAt(world, ray);
//			setPixel(x, y, color);
//			update();
//			processEvents();
//		}
//	}
//}