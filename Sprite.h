#pragma once
#include "Vec2.h"
class Sprite
{
protected:
	Vec2<float> _position;
	Vec2<float> _velocity;
	bool _actif;
public:
	Sprite();
	virtual void Update();
	virtual void Draw();
	bool isEnabled();

};

