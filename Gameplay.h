#pragma once
#include <list>
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "Cam2D.h"

class Gameplay : public Scene
{
private:
	Player player;
	float _delay;
	bool _gamePaused;
	Cam2D _cam;
	void InitObjects();
	void Controls();
	void Collision();
public:
	// Constructeur
	Gameplay();


	// Méthodes override
	void Init() override;
	void Update() override;
	void Draw() override;
	
	// Méthodes
	void ScoringSystem();
	int playerDeath();
	Cam2D GetCamera();
};