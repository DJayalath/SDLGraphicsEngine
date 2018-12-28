# SDLGameEngine
A class for quickly setting up and running the SDL graphics library

## How to use
A class in your main program must override the initialisation and
update functions in the SDLGraphicsEngine class as below:

```c_cpp
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

```int main(int argc, char* argv[])
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
