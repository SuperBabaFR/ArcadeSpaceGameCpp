#pragma once
#include "Vec2.h"
#include "Couleur.h"
#include "Rect.h"
#include "Sprite.h"

class Bullet : public Sprite
{
	private : 
		Vec2<float> _size;
		float _rotation;
		float _speed;
		int _damage;
		Couleur _color;
		float _lifeTime;

	public :
		Bullet(Vec2<float> position, Vec2<float> size, int damage, Couleur color);
		Bullet();
		void Init(Vec2<float> baseVelocity, float speed, float rotation);
		void Update() override;
		void Draw() override;
		Vec2<float> GetPosition();
};

