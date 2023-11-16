#include "settings.h"
#include "Game.h"

int main()
{
	Game game{
		stg::screenWidth,
		stg::screenHeight,
		stg::screenTitle
	};

	game.Init();

	while (!game.GameShouldClose())
	{
		game.Tick();
	}

	return 0;
}