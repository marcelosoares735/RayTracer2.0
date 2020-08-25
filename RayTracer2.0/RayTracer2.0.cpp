// RayTracer2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Canvas.h"
#include "Matrix.h"
#include "SDL.h"



int main(int argc, char *argv[])
{
	Canvas canvas(800, 600);
	

	if (canvas.init() == false) return -1;

	canvas.setPixel(400, 300, { 1,1,1 });
	canvas.setPixel(401, 300, { 1,1,1 });
	canvas.setPixel(402, 300, { 1,1,1 });
	canvas.setPixel(403, 300, { 1,1,1 });
	canvas.setPixel(404, 300, { 1,1,1 });
	canvas.setPixel(405, 300, { 1,1,1 });
	canvas.setPixel(406, 300, { 1,1,1 });
	canvas.update();
	canvas.processEvents();

	while (true) {
		if (canvas.processEvents() == false)
			break;
	}

	canvas.close();
	return 0;
}


