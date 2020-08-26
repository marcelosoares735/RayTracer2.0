// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../RayTracer2.0/Ray.h"
#include "SDL.h"
#include "../RayTracer2.0/Canvas.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Canvas canvas(100, 100);

	if (!canvas.init()) return -1;

	Sphere s;
	//s.Rotate(Matrix::GetScalingMat(1, 3, 1));
	canvas.render(s);

	while (true) {
		if (canvas.processEvents() == false)
			break;
	}

	canvas.close();
	return 0;
	Ray r;
    std::cout << "Hello World!\n";
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
