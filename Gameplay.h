#pragma once
#include <list>
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include "settings.h"
#include "RaylibWrapper.h"
#include "Cam2D.h"
#include "StarryBackground.h"

class Gameplay : public Scene
{
private:
	std::shared_ptr<Player> player;
	int _nbBullets;
	float _delay;
	bool _gamePaused;
	Cam2D _cam;
	StarryBackground _background;
	void InitObjects();
	void Controls();
	void Collision();
public:
	// Constructeur
	Gameplay();

	// M�thodes override
	void Init() override;
	void Update() override;
	void Draw() override;
	
	// M�thodes
	void ScoringSystem();
	void BulletUpdate();
	int playerDeath();
	Cam2D GetCamera();
};