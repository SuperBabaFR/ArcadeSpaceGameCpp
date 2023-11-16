#include "MenuPrincipal.h"
#include "RaylibWrapper.h"
#include "settings.h"
#include <string>


MenuPrincipal::MenuPrincipal() : Scene(Menu)
{
	
}

void MenuPrincipal::Init()
{
	Vec2<float> dimensions{ 150, 75 };
	int nbButtons = 3;
	float screenXcenter = stg::screenWidth / 2.0f;
	float posY = stg::screenHeight / static_cast<float>(nbButtons + 1);
	_play.Init({ screenXcenter, posY * 3 }, dimensions, "Jouer", VERTFONCE);
}

void MenuPrincipal::Update()
{
	Vec2<float> mousePos = raywrp::GetMousePositionV();
	_play.Update(mousePos);
}

void MenuPrincipal::Draw()
{
	Scene::Draw();
	std::string copyright{ "Copyright 2023 - KrakenWood (Bastien)" };
	int textLength{ raywrp::MesureText(copyright, 20) };
	raywrp::DrawTextV(copyright, { float(stg::screenWidth - textLength), float(stg::screenHeight - 20)}, 20, BLANC);
	raywrp::DrawTextV("Jeu", { -69, -69 }, 50, BLANC);
	_play.Draw();
}

bool MenuPrincipal::IsSceneSwitching()
{
	return _play.IsClicked();
}

// Remettre la variable a faux

