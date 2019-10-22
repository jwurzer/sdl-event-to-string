#include <SDL_main.h>
#include <SDL.h>
#include <iostream>

#include <sdl_events_trace.h>

int main(int argc, char* args[])
{
	int width = 800;
	int height = 600;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("SDL Event Viewer",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_SHOWN
			| SDL_WINDOW_RESIZABLE
			| SDL_WINDOW_ALLOW_HIGHDPI
			);
	if (!window) {
		std::cerr << "Window could not be created! SDL_Error: " <<
				SDL_GetError() << std::endl;
		SDL_Quit();
		return 2;
	}

	// flags for renderer creation
	unsigned int flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

	// Create the renderer
	// Second parameter is the index of the rendering driver to initialize.
	// Set to -1 to initialize the first one supporting the requested flags.
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, flags);
	if (!renderer) {
		std::cerr << "renderer could not be created! SDL Error: " <<
				SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	bool running = true;
	SDL_Event e;

	while (running) {
		while (SDL_PollEvent(&e)) {
			std::cout << sdlEventToString(e);
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

