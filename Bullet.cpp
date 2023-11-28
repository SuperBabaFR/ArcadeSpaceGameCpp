#include "Bullet.h"
#include "RaylibWrapper.h"
#include <math.h>

Bullet::Bullet(Vec2<float> position, Vec2<float> size, int damage, Couleur color) : _damage(damage), _color(color), _size(size)
{
	_position = position;
	_velocity = { 0,0 };
	_speed = 0;
	_rotation = 0;
	_lifeTime = 0;
}

Bullet::Bullet()
{
	_position = { 0,0 };
	_velocity = { 0,0 };
	_speed = 0;
	_rotation = 0;
	_size = { 0,0 };
	_damage = 0;
	_lifeTime = 0;
	_color = BLANC;
}

void Bullet::Init(Vec2<float> baseVelocity, float speed, float rotation)
{
	_speed = speed;
	_rotation = rotation;
	
	float force_x = (float)cos(rotation * DEG2RAD) * _speed * raywrp::GetDeltaTime();
	float force_y = (float)sin(rotation * DEG2RAD) * _speed * raywrp::GetDeltaTime();

	_velocity.SetX(force_x);
	_velocity.SetY(force_y);

	if (baseVelocity.GetX() > 0 && _velocity.GetX() > 0
		|| baseVelocity.GetX() < 0 && _velocity.GetX() < 0)
	{
		_velocity.SetX(_velocity.GetX() + baseVelocity.GetX());
	}

	if (baseVelocity.GetY() > 0 && _velocity.GetY() > 0
		|| baseVelocity.GetY() < 0 && _velocity.GetY() < 0)
	{
		_velocity.SetY(_velocity.GetY() + baseVelocity.GetY());
	}
	_lifeTime = 10.0f;
	_actif = true;
}

void Bullet::Update()
{
	Sprite::Update();
	if (_lifeTime > 0)
	{
		_lifeTime -= raywrp::GetDeltaTime();
	}
	else
	{
		_actif = false;
	}
}

void Bullet::Draw()
{
	Rect forme{ _position.GetX(), _position.GetY(), _size.GetX(), _size.GetY() };
	Vec2<float> origin = _size / 2.0f;
	
	raywrp::DrawRectangle(forme, origin, _rotation, _color);
	// raywrp::DrawCircleV(_position, _size.GetY(), _color);
}


Vec2<float> Bullet::GetPosition()
{
	return _position;
}