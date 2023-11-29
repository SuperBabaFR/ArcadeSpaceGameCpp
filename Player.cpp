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
}

void Player::SetRotation(float rotation)
{
	_rotation = rotation;
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
	if (type == 1)
	{
		bullet->Create( _position, {20,10}, 5, BLEU );
		bullet->Init(_velocity, 500, _rotation);
	}
	else if (type == 2)
	{
		bullet->Create( _position, {30,15}, 10, ROUGE );
		bullet->Init(_velocity, 300, _rotation);
	}

	return bullet;
}

Vec2<float> Player::GetPosition()
{
	return _position;
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
