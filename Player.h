#pragma once
#include "Vec2.h"
#include "Couleur.h"
#include "Rect.h"
#include "Bullet.h"
#include "Sprite.h"
#include <iostream>

struct BulletStats {
	Vec2<float> size;
	float max_cooldown;
	int damage;
	float speed;
	Couleur color;
	float cooldown;
};

class Player : public Sprite
{
private:
	float _rotation;
	float _power;
	float _size;
	Couleur _color;
	Vec2<float> _canonSize;
	float const MAXSPEED = 5.0f;
	// Light Shoot stats
	BulletStats LIGHT_BULLET{ { 20, 10}, .5f, 5, 500, BLEU, 0 };

	// Heavy Shoot stats
	BulletStats HEAVY_BULLET{ { 20, 12}, .75f, 10, 300, ROUGE, 0 };
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