#pragma once
#include "Vec2.h"
#include "Couleur.h"
#include "Rect.h"
#include "Bullet.h"
#include "Sprite.h"
#include <iostream>

class Player : public Sprite
{
private:
	float _rotation;
	float _power;
	float const MAXSPEED = 5.0f;
	float _size;
	Couleur _color;
	Vec2<float> _canonSize;
public:
	// Constructeur
	Player();
	void Init(float x, float y);
	void Update() override;
	void SetRotation(float rotation);
	void Draw() override;
	// Methods
	void Reactor();
	std::shared_ptr<Bullet> Shoot(int type);
	Vec2<float> GetPosition();
};