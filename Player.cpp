#include "Player.h"
#include "RaylibWrapper.h"
#include "settings.h"

Player::Player()
{	
	_rotation = 0;
	_size = 25;
	_canonSize = { _size * 2.5f, _size };
	_power = 10.0f;
}

void Player::Init(float x, float y)
{
	_position = Vec2<float>(x, y);
	_actif = true;
}

void Player::Update()
{
	Sprite::Update();

	if (HEAVY_BULLET.cooldown > 0)
		HEAVY_BULLET.cooldown -= raywrp::GetDeltaTime();

	if (LIGHT_BULLET.cooldown > 0)
		LIGHT_BULLET.cooldown -= raywrp::GetDeltaTime();
}

void Player::Draw()
{
	Rect forme { _position.GetX(), _position.GetY(), _canonSize.GetX(), _canonSize.GetY() };
	Vec2<float> origin{ _size / 2, _size / 2 };

	// Canon
	raywrp::DrawRectangle(forme, origin, _rotation, GRIS);
	// Base du joueur
	raywrp::DrawCircleV(_position, _size, BLEU);
}

void Player::Reactor()
{
	float force_x = (float)cos(_rotation * DEG2RAD) * _power * raywrp::GetDeltaTime();
	float force_y = (float)sin(_rotation * DEG2RAD) * _power * raywrp::GetDeltaTime();

	_velocity.SetX(_velocity.GetX() + force_x);
	_velocity.SetY(_velocity.GetY() + force_y);

	if (abs(_velocity.GetX()) >= MAXSPEED)
		_velocity.SetX((_velocity.GetX() > 0) ? MAXSPEED : -MAXSPEED);

	if (abs(_velocity.GetY()) >= MAXSPEED)
		_velocity.SetY((_velocity.GetY() > 0) ? MAXSPEED : -MAXSPEED);
}

std::shared_ptr<Bullet> Player::Shoot(int type)
{
	auto bullet = std::make_shared<Bullet>();
	if (type == 1 && LIGHT_BULLET.cooldown <= 0)
	{
		bullet->Create(_position, LIGHT_BULLET.size, LIGHT_BULLET.damage, LIGHT_BULLET.color);
		bullet->Init(_velocity, LIGHT_BULLET.speed, _rotation);

		LIGHT_BULLET.cooldown = LIGHT_BULLET.max_cooldown;
	}
	else if (type == 2 && HEAVY_BULLET.cooldown <= 0)
	{
		bullet->Create(_position, HEAVY_BULLET.size, HEAVY_BULLET.damage, HEAVY_BULLET.color);
		bullet->Init(_velocity, HEAVY_BULLET.speed, _rotation);

		HEAVY_BULLET.cooldown = HEAVY_BULLET.max_cooldown;
	}

	return bullet;
}

Vec2<float> Player::GetPosition()
{
	return _position;
}

void Player::SetRotation(float rotation)
{
	_rotation = rotation;
}