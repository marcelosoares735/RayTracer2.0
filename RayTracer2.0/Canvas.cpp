// ReSharper disable CppFunctionalStyleCast
#include "Canvas.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <fstream>
#include "Camera.h"
#include "Ray.h"
#include "Intersection.h"
#include "Lighting.h"


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

	m_buffer = new Uint32[Uint32(width)*Uint32(height)];

	memset(m_buffer, 0, Uint32(width)*Uint32(height) * sizeof(Uint32));

	update();

	return true;
}

void Canvas::setPixel(int x, int y, Color color) {
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	
	Uint32 finalColor = 0;

	Uint8 r = Uint8 (std::clamp(color.r * 255.f, 0.f, 255.f));
	Uint8 g = Uint8 (std::clamp(color.g * 255.f, 0.f, 255.f));
	Uint8 b = Uint8 (std::clamp(color.b * 255.f, 0.f, 255.f));
	finalColor += (r << 24 | g << 16 | b << 8 | 0xff );
	/*finalColor += r;
	finalColor <<= 8;
	finalColor += g;
	finalColor <<= 8;
	finalColor += b;
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
	memset(m_buffer, 0, size_t(width) * size_t(height) * sizeof(Uint32));
}



void Canvas::render(const World& world, const Camera& camera) {
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			const Ray ray = camera.RayForPixel(x, y);
			const Color color = ColorAt(world, ray);
			setPixel(x, y, color);
		}
	}

	WritePPM();
}

void Canvas::WritePPM() {
	std::ofstream img;
	img.open("RayTracer.ppm");
	img << "P3" << std::endl;
	char str1[30];
	char str2[30];

	_itoa_s(width, str1, 10);
	_itoa_s(height, str2, 10);
	img << str1 << " " << str2 << std::endl;
	_itoa_s(255, str1, 10);
	img << str1 << std::endl;
	int elementoLinha = 0;
	for (int i = 0; i < width * height; i++) {
		char red[10], green[10], blue[10];
		int r = (m_buffer[i] & 0xff000000) >> 24;
		int g = (m_buffer[i] & 0x00ff0000) >> 16;
		int b = (m_buffer[i] & 0x0000ff00) >> 8;
		_itoa_s(r, red, 10);
		_itoa_s(g, green, 10);
		_itoa_s(b, blue, 10);

		img << red << " " << green << " " << blue;
		if (elementoLinha == 17)
			img << std::endl;
		else
			img << " ";

		elementoLinha++;
	}

	img.close();
	std::cout << "Saved PPM image" << std::endl;
}
