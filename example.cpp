#include "SDLGraphicsEngine.h"

using namespace std;

class Game : public SDLGraphicsEngine
{
public:
	void OnInitialisation() override
	{
	}

	void OnUpdate() override
	{
	}

private:
};

int main(int argc, char* argv[])
{
	Game game;
	game.ConstructWindow(1280, 720, "Test window");
	game.Start();
	game.CleanUp();
	return 0;
}
