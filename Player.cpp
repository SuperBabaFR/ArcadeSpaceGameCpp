#include "Player.h"
#include "RaylibWrapper.h"
#include "settings.h"
#include <numbers>

Player::Player()
{	
	_speed = 500;
	_rotation = 60;
	_size = 25;
	_canonSize = { _size * 2.5f, _size };
}

void Player::Init(float x, float y)
{
	_position = Vec2<float>(x, y);
	_actif = true;
}

void Player::Update()
{
	if (IsKeyDown(KEY_W))
		_velocity.SetY(_velocity.GetY() - _speed * raywrp::GetDeltaTime());
	else if (IsKeyDown(KEY_S))
		_velocity.SetY(_velocity.GetY() + _speed * raywrp::GetDeltaTime());

	if (IsKeyDown(KEY_A))
		_velocity.SetX(_velocity.GetX() - _speed * raywrp::GetDeltaTime());
	else if (IsKeyDown(KEY_D))
		_velocity.SetX(_velocity.GetX() + _speed * raywrp::GetDeltaTime());

	// _rotation = ;
	
	

	if (IsKeyDown(KEY_E))
		_rotation -= 1;
	else if (IsKeyDown(KEY_Q))
		_rotation += 1;


	Sprite::Update();

	_velocity = { 0,0 };
}

void Player::SetRotation(float rotation)
{
	_rotation = rotation;
}

void Player::Reactor()
{

}

Vec2<float> Player::GetPosition()
{
	return _position;
}

void Player::Draw()
{
	Rect forme { _position.GetX(), _position.GetY(), _canonSize.GetX(), _canonSize.GetY() };
	Vec2<float> origin{ _size / 2, _size / 2 };

	raywrp::DrawRectangle(forme, origin, _rotation, GRIS);

	raywrp::DrawCircleV(_position, _size, BLEU);
}
