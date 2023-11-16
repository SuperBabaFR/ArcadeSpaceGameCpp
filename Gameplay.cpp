#include <iostream>
#include "Gameplay.h"
#include "settings.h"
#include "raylib.h"
#include "RaylibWrapper.h"

Gameplay::Gameplay() : Scene(Jeu), player(), _cam()
{
	_delay = 3.0f;
	_gamePaused = false;

	_cam.SetTarget({ 0, 0 });
	_cam.SetOffset({ stg::screenWidth / 2.0f , stg::screenHeight / 2.0f });
}

void Gameplay::InitObjects()
{
	_listSprite.clear();
	// Positionnement des joueurs
	player.Init(stg::screenWidth / 2.0f, stg::screenHeight / 2.0f);
	// Ajout des sprites
	_listSprite.push_back(&player);
}

void Gameplay::Init()
{
	// Sounds effects 
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
	for (auto sprite : _listSprite)
	{
		if (sprite->isEnabled())
		{
			sprite->Draw();
		}
	}
	raywrp::EndDraw2D();
}