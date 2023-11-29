#include <iostream>
#include "Gameplay.h"

Gameplay::Gameplay() : Scene(Jeu), player(std::make_shared<Player>()), _cam(), _background(stg::StarAmount, 20, 100)
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
	player->Init(stg::screenWidth / 2.0f, stg::screenHeight / 2.0f);
	// Ajout des sprites
	_listSprite.push_back(player);
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

	float rotation = raywrp::Vec2AngleDeg(player->GetPosition(), mousePos);
	
	player->SetRotation(rotation);

	if (IsKeyDown(KEY_SPACE))
	{
		player->Reactor();
	}

	if (IsMouseButtonDown(0))
	{
		// Bullet tir = player.Shoot(1);
		// _listBullets.push_back(tir);
		_nbBullets++;
		_listSprite.push_back(player->Shoot(1));
	}
	else if (IsMouseButtonDown(1))
	{
		// Bullet tir = player.Shoot(2);
		// _listBullets.push_back(tir);
		_nbBullets++;
		_listSprite.push_back(player->Shoot(2));
	}
}

void Gameplay::Collision()
{

}


void Gameplay::ScoringSystem()
{

}

void Gameplay::BulletUpdate()
{
	// Bullet update
	for (auto it = _listSprite.begin(); it != _listSprite.end();) {
		auto sprite = *it;

		// Essayez de convertir le pointeur de base en un pointeur de Bullet
		if (auto bullet = std::dynamic_pointer_cast<Bullet>(sprite)) {
			if (bullet->isEnabled()) {
				bullet->Update();
				++it;
			}
			else {
				it = _listSprite.erase(it);
				_nbBullets--;
			}
		}
		else {
			// C'est un sprite qui n'est pas un Bullet, effectuez une mise à jour générique ici si nécessaire
			sprite->Update();
			++it;
		}
	}
}

void Gameplay::Update()
{
	Controls();

	_background.Update(player->GetPosition());

	BulletUpdate();

	for (auto& sprite : _listSprite)
	{
		sprite->Update();
	}

	_cam.SetTarget(player->GetPosition());

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

		
		for (auto& sprite : _listSprite)
		{
			if (sprite->isEnabled() && !sprite->isItThatObject(Joueur))
			{
				sprite->Draw();
			}
		}

		player->Draw();

		std::string text{ "Nombre d'etoiles : " };
		text += std::to_string(_background.GetStarAmount());
		raywrp::DrawTextV(text, { 100,500 }, 20, VIOLETFONCE);

		text = "Nombre de tirs : ";
		text += std::to_string(_nbBullets);
		raywrp::DrawTextV(text, { 500,500 }, 20, VIOLETFONCE);

	raywrp::EndDraw2D();
}