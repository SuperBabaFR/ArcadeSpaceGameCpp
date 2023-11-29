#include "Sprite.h"
#include "Vec2.h"

Sprite::Sprite()
{
	_position = Vec2<float>(0.0f, 0.0f);
	_velocity = Vec2<float>(0.0f, 0.0f);
	_actif = false;
}

void Sprite::Update()
{
	_position += _velocity;
}


void Sprite::Draw()
{
}

bool Sprite::isEnabled()
{
	return _actif;
}

bool Sprite::isItThatObject(ObjectType type)
{
	return type == _type;
}
