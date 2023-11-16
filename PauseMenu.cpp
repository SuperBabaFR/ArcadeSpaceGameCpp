#include "PauseMenu.h"
#include "RaylibWrapper.h"
#include "settings.h"

PauseMenu::PauseMenu() : Scene(Pause)
{
	
}

void PauseMenu::Init()
{
	Vec2<float> dimensions{ 300, 75 };
	int nbButtons = 3;
	float screenXcenter = static_cast<float>(stg::screenWidth / 2);
	float posY = stg::screenHeight / static_cast<float>(nbButtons + 1) * 2;
	float offsetY = 50 + dimensions.GetY();

	_resume.Init({ screenXcenter, posY }, dimensions, "Reprendre", VERTFONCE);
	_reset.Init({ screenXcenter, posY + offsetY }, dimensions, "Recommencer", VERTFONCE);
	_quit.Init({ screenXcenter, posY + offsetY * 2 }, dimensions, "Quitter", VERTFONCE);
}

void PauseMenu::Update()
{
	Vec2<float> mousePos = raywrp::GetMousePositionV();
	_resume.Update(mousePos);
	_reset.Update(mousePos);
	_quit.Update(mousePos);

}

void PauseMenu::Draw()
{
	Scene::Draw();
	raywrp::DrawTextV("Pause", { -69, stg::screenHeight / (3 + 1) }, 50, BLANC);
	_resume.Draw();
	_reset.Draw();
	_quit.Draw();
}

int PauseMenu::IsSceneSwitching()
{
	int Action = 0;
	
	if (_resume.IsClicked() || IsKeyPressed(KEY_ESCAPE))
	{
		Action = 1;
	}
	else if (_reset.IsClicked())
	{
		Action = 2;
	}
	else if (_quit.IsClicked())
	{
		Action = 3;
	}
	return Action;
}
// Remettre la variable a faux