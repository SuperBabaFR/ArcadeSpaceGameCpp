#pragma once
#include "Vec2.h"

enum ObjectType {
	Joueur,
	Balle,
	Asteroide,
	Mob
};

class Sprite
{
protected:
	Vec2<float> _position;
	Vec2<float> _velocity;
	bool _actif;
	ObjectType _type;
public:
	Sprite();
	virtual void Update();
	virtual void Draw();
	bool isEnabled();
	bool isItThatObject(ObjectType type);
};

