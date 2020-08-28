// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../RayTracer2.0/Ray.h"
#include "SDL.h"
#include "../RayTracer2.0/Canvas.h"
#include "../RayTracer2.0/Lighting.h"
#include "../RayTracer2.0/ConfigLoader.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Config config;
	config.Load();
	
	Canvas canvas(config.screen_width, config.screen_height);

	if (!canvas.init()) return -1;
	Sphere s(Material(Color(1,0.2f,1)));
	
	PointLight light(Vec4::MakePoint(-10, 10, -10), Color(1, 1, 1));
	canvas.render(s, light);

	canvas.WritePPM();
	
	while (true) {
		if (canvas.processEvents() == false)
			break;
	}

	canvas.close();
	return 0;
	
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
