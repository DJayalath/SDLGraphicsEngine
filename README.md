# SDLGraphicsEngine
A class for quickly setting up and running the SDL graphics library.

## Warning
You should note that this is not intended for fast or efficient graphics manipulation. It's for ease of use in setting up the SDL library in projects that use individual pixel manipulation. Examples of projects this would be useful for are plotting the Mandelbrot set, drawing cells in cellular automata, demonstrating algorithms visually, etc. this is not suitable for making 2D or 3D games since it only provides individual pixel manipulation functionality.

## How to use
A class in your main program must override the initialisation and
update functions in the SDLGraphicsEngine class as below:

```cpp
class GraphicsEngineRunner : public SDLGraphicsEngine
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
```
Obviously 'GraphicsEngineRunner' can be renamed to whatever you like. This custom class must then be called in the main function such as
in the example given below:

```cpp
int main(int argc, char* argv[])
{
  GraphicsEngineRunner game;
  game.ConstructWindow(1280, 720, "Test window");
  game.Start();
  game.CleanUp();
  return 0;
}
```

NOTE: the parameters of main() must be exactly as above else SDL
fails to insert its own SDL_main function before it.

View `example.cpp` to see how the instructions tie together.
