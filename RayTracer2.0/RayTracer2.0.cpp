// RayTracer2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SDL.h"
#include <iostream>
#include "Canvas.h"
#include "Matrix.h"


int main(int argc, char *argv[])
{
	Canvas canvas(800, 600);

	float aux[] = { 1,5,0,-3,2,7,0,6,-3,0,0,0,0,0,0,0 };
	Matrix a(aux, 3);
	float auxb[] = { -3,2,0,6,0,0,0,0,0,0,0,0,0,0,0,0 };
	Matrix b(auxb, 2);
	Matrix::GetSubMatrix(a,0,2);

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


