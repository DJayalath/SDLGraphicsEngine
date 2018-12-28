#include "SDLGraphicsEngine.h"

using namespace std;

class GraphicsEngineRunner : public SDLGraphicsEngine
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
	GraphicsEngineRunner program;
	program.ConstructWindow(1280, 720, "Test window");
	program.Start();
	program.CleanUp();
	return 0;
}
