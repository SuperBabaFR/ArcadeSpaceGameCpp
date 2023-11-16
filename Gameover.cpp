#include "Gameover.h"
#include "RaylibWrapper.h"
#include "settings.h"

Gameover::Gameover() : Scene(PartieFinie)
{
	_screenText = "";
}

void Gameover::Init()
{
	Vec2<float> dimensions{ 150, 75 };
	int nbButtons = 3;
	float screenXcenter = stg::screenWidth / 5.0f;
	float posY = stg::screenHeight / static_cast<float>(nbButtons + 1);
	_rematch.Init({ screenXcenter * 1, posY * 3 }, dimensions, "Rejouer", VERTFONCE);
	_quit.Init({ screenXcenter * 4, posY * 3 }, dimensions, "Quitter", VERTFONCE);
}

void Gameover::SetScore(int score)
{

}


void Gameover::Update()
{
	Vec2<float> mousePos = raywrp::GetMousePositionV();
	_rematch.Update(mousePos);
	_quit.Update(mousePos);
}

void Gameover::Draw()
{
	Scene::Draw();
	raywrp::DrawTextV(_screenText, { -69, -69 }, 50, VERT);
	_rematch.Draw();
	_quit.Draw();
}

int Gameover::IsSceneSwitching()
{
	int Action = Nothing;

	if (_rematch.IsClicked())
	{
		Action = Reset;
	}
	else if (_quit.IsClicked())
	{
		Action = Quit;
	}
	return Action;
}