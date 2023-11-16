#pragma once
#include "Vec2.h"
#include "Couleur.h"
#include "Rect.h"
#include "Sprite.h"
#include "raylib.h"

class Player : public Sprite
{
private:
	float _rotation;
	float _speed;
	float const MAXSPEED = 500.0;
	Couleur _color;
public:
	// Constructeur
	Player();
	void Init(float x, float y);
	void Update() override;
	void Draw() override;
	// Methods
	void Reactor();
	Vec2<float> GetPosition();
};