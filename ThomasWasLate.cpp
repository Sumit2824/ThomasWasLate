// ThomasWasLate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
// Make code easier to type with “using namespace”
using namespace sf;
// This is where our game starts from
int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the

	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	while (window.isOpen())
	{
	/*
		      
		        Handle the players input
				*/

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		        ****************************************
		        Update the scene
				*/

		window.clear();
		window.display();
	
	}
	return 0;
}

