#include <SDL_main.h>
#include <SDL.h>
#include <stdio.h>

#include <sdl_event_to_string.h>

#define MAX_EVT_STR 256

int main(int argc, char* args[])
{
	int width = 800;
	int height = 600;
	char evtStr[MAX_EVT_STR];

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
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
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
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
		printf("renderer could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	int running = 1;
	SDL_Event e;

	while (running) {
		while (SDL_PollEvent(&e)) {
			printf("***%s***\n", sdlEventToCString(evtStr, MAX_EVT_STR, &e));
			if (e.type == SDL_QUIT) {
				running = 0;
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

