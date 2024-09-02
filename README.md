# Crater
Crater is a simple game framework for c++ that's build on top of SDL2


**Basic Window Example:**
```
#include "Crater/RenderWindow.hpp"

int main(int argc, char* argv[])
{
	cr::RenderWindow window("Empty Crater Window", 1280, 720);
	SDL_Event event;
	//window.gameScale = 4;

	// Initialize
	

	while (window.isOpen)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				window.isOpen = false;
			}
		}

		// Update


		// Draw here
		//window.clear();

		//window.display();
	}

	window.cleanUp();
	return 0;
}
```
