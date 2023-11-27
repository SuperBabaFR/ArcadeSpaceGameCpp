#include <iostream>
#include "Gameplay.h"

Gameplay::Gameplay() : Scene(Jeu), player(), _cam(), _background(stg::StarAmount, 20, 100)
{
	_delay = 3.0f;
	_gamePaused = false;

	_cam.SetTarget({ 0, 0 });
	_cam.SetOffset({ stg::screenWidth / 2.0f , stg::screenHeight / 2.0f });
}

void Gameplay::InitObjects()
{
	_listSprite.clear();
	// Positionnement du joueur
	player.Init(stg::screenWidth / 2.0f, stg::screenHeight / 2.0f);
	// Ajout des sprites
	_listSprite.push_back(&player);
}

void Gameplay::Init()
{
	// Background
	_background.Init();
	InitObjects();
}

void Gameplay::Controls()
{
	Vec2<float> mousePos;
	mousePos = raywrp::GetScreenToWorld2DPoint(raywrp::GetMousePositionV(), _cam);

	float rotation = raywrp::Vec2AngleDeg(player.GetPosition(), mousePos);
	
	player.SetRotation(rotation);
}

void Gameplay::Collision()
{

}


void Gameplay::ScoringSystem()
{

}

void Gameplay::Update()
{
	Controls();

	_background.Update(player.GetPosition());

	for (auto sprite : _listSprite)
	{
		sprite->Update();
	}

	_cam.SetTarget(player.GetPosition());

	Collision();

	ScoringSystem();
}

int Gameplay::playerDeath()
{
	int death = 0;
	
	return death;
}

Cam2D Gameplay::GetCamera()
{
	return _cam;
}

void Gameplay::Draw()
{	
	DrawFPS(0, 0);
	
	raywrp::BeginDraw2D(_cam);
		
		_background.Draw();
		
		for (auto sprite : _listSprite)
		{
			if (sprite->isEnabled())
			{
				sprite->Draw();
			}
		}

		std::string text{ "Nombre d'etoiles : " };
		text += std::to_string(_background.GetStarAmount());
		raywrp::DrawTextV(text, { 100,500 }, 20, VIOLETFONCE);

		raywrp::DrawCircleV({0,0}, 20, BLANC);

	raywrp::EndDraw2D();
}