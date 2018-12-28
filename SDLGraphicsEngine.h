/*
--------------------- SDL Graphics Engine ---------------------
A class used for setting up SDL graphics quickly and easily.

HOW TO USE:

A class in the main program must override the initialisation and
update functions in the GraphicsEngine class as below:

	class GraphicsEngineRunner : public GraphicsEngine
	{
	public:
		void OnInitialisation() override
		{
			// Initialisation instructions...
		}

		void OnUpdate() override
		{
			// Game loop instructions...
		}
	private:
		// Variables go here
	};

Obviously 'GraphicsEngineRunner' can be renamed to whatever you like.

This custom class must then be called in the main function such as
in the example given:

	int main(int argc, char* argv[])
	{
		GraphicsEngineRunner game;
		game.ConstructWindow(1280, 720, "Test window");
		game.Start();
		game.CleanUp();
		return 0;
	}

NOTE: the parameters of main() must be exactly as above else SDL
fails to insert its own SDL_main function before it.
*/

#pragma once

#include <SDL.h>
#include <memory>

class GraphicsEngine
{
public:
	GraphicsEngine()
	{
		// Set all inputs to false initially
		memset(m_keys, false, NUM_KEYS * sizeof(bool));
		memset(m_mouse, false, NUM_MOUSE * sizeof(bool));
	}
	~GraphicsEngine() {}
	struct Colour
	{
		Colour(Uint8 red, Uint8 green, Uint8 blue)
		{
			r = red;
			g = green;
			b = blue;
		}

		Uint8 r, g, b;
	};
	void ConstructWindow(unsigned int w, unsigned int h, const char* title)
	{
		// Create window
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

		width = w; height = h;

		// Setup surface for updating pixels
		surface = SDL_GetWindowSurface(window);
	}
	void CleanUp()
	{
		// Deallocate surface
		SDL_FreeSurface(surface);
		// Destroy window 
		SDL_DestroyWindow(window);
		// Quit SDL subsystems 
		SDL_Quit();
	}
	void Draw(int x, int y, Colour c, int px_size = 1)
	{
		Uint8* pixel_ptr = (Uint8*)surface->pixels + (y * px_size * width + x * px_size) * 4;
		for (unsigned int i = 0; i < px_size; i++)
		{
			for (unsigned int j = 0; j < px_size; j++)
			{
				*(pixel_ptr + j * 4) = c.b;
				*(pixel_ptr + j * 4 + 1) = c.g;
				*(pixel_ptr + j * 4 + 2) = c.r;
			}
			pixel_ptr += width * 4;
		}
	}
	void Start()
	{
		OnInitialisation();
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				switch (e.type)
				{
				case SDL_KEYDOWN:
					if (e.key.keysym.sym < 128)
						m_keys[e.key.keysym.sym] = true;
					break;
				case SDL_KEYUP:
					if (e.key.keysym.sym < 128)
						m_keys[e.key.keysym.sym] = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					m_mouse[e.button.button] = true;
					break;
				case SDL_MOUSEBUTTONUP:
					m_mouse[e.button.button] = false;
					break;
				case SDL_QUIT:
					quit = true;
					break;
				default:
					break;
				}
			}

			OnUpdate();
			SDL_UpdateWindowSurface(window);
		}
	}
private:

	virtual void OnInitialisation() = 0;
	virtual void OnUpdate() = 0;

	static constexpr unsigned int NUM_KEYS = 128;
	static constexpr unsigned int NUM_MOUSE = 5;

	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	unsigned int width, height;
	SDL_Event e;
	bool quit = false;
	bool m_keys[NUM_KEYS], m_mouse[NUM_MOUSE];
};