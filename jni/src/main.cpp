#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list>

#include <SDL.h>
#include "TestValueProvider.h"

#ifdef _WIN64
#define SDL_main main
#elif _WIN32
#define SDL_main main
#endif

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char *argv[])
{

	TestValueProvider valueProvider(1);
	std::list<long double> values;

	long double e = 0.00001;

	SDL_Window *window;
	SDL_Renderer *renderer;

	if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0)
		exit(2);

	/* Main render loop */
	Uint8 done = 0;
	SDL_Event event;

	while(!done)
	{
		/* Check for events */
		while(SDL_PollEvent(&event))
		{
			switch (event.type) {
			case SDL_QUIT: {
				done = 1;
				break;
						   }
			case SDL_KEYDOWN: {
				switch (event.key.keysym.sym) {
				case (SDLK_UP): {
					if (event.key.keysym.mod && KMOD_LSHIFT) {
						e+=0.001;
					} else {
						e+=0.0001;
					}
					break;
								}
				case (SDLK_DOWN): {
					if (event.key.keysym.mod && KMOD_LSHIFT) {
						e-=0.001;
					} else {
						e-=0.0001;
					}
					break;
								  }
				case (SDLK_LEFT): {
					if (e > 0) e=-e;
					break;
								}
				case (SDLK_RIGHT): {
					if (e < 0) e=-e;
					break;
								  }
				case (SDLK_SPACE): {
					valueProvider.setPosition(((int)rand() % 40)*((int)rand() % 2 == 0 ? -100 : 100));
					break;
								  }
				default: {
					break;
						 }
				}
							  }
			default: {
				break;
					 }
			}
		}


		/* Draw a gray background */
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
		long double value = valueProvider.getNextValue(e);
		int size = values.size();
		if (size >= WIDTH-256) values.pop_front();
		values.push_back(value);
		printf("e=%5f x=%20.16f y=%20.16f\n", e, valueProvider.getCurrentPosition(), value);
		int x = 0;
		long double offsetY = -value + HEIGHT / 2;
		std::list<long double>::iterator end = values.end();
		end--;
		if (size > 1) {
			for (std::list<long double>::iterator i = values.begin();i!=end;i++) {
				std::list<long double>::iterator next = i;
				next++;
				SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
				SDL_RenderDrawLine(renderer, x, (*i)+offsetY, x+1, (*next)+offsetY);
				SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderDrawPoint(renderer, x, (*i)+offsetY);
				SDL_RenderDrawPoint(renderer, x+1, (*next)+offsetY);
				x++;
			}
		}
		//draw(window, renderer, sprite);

		/* Update the screen! */
		SDL_RenderPresent(renderer);

		SDL_Delay(10);
	}

	exit(0);
}