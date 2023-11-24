#include <iostream>
#include "Gameplay.h"

Gameplay::Gameplay() : Scene(Jeu), player(), _cam(), _background(stg::screenWidth, 20, 100)
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
	raywrp::BeginDraw2D(_cam);
		
		_background.Draw();
		
		for (auto sprite : _listSprite)
		{
			if (sprite->isEnabled())
			{
				sprite->Draw();
			}
		}

		raywrp::DrawCircleV({0,0}, 20, BLANC);

	raywrp::EndDraw2D();
}