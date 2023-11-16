#include "Player.h"
#include "RaylibWrapper.h"
#include "settings.h"
#include "raylib.h"

Player::Player()
{	
	_speed = 5;
	_rotation = 0;
}

void Player::Init(float x, float y)
{
	_position = Vec2<float>(x, y);
	_actif = true;
}

void Player::Update()
{
	if (IsKeyDown(KEY_W))
		_velocity.SetY(_velocity.GetY() - _speed);
	else if (IsKeyDown(KEY_S))
		_velocity.SetY(_velocity.GetY() + _speed);

	if (IsKeyDown(KEY_A))
		_velocity.SetX(_velocity.GetX() - _speed);
	else if (IsKeyDown(KEY_D))
		_velocity.SetX(_velocity.GetX() + _speed);

	
	Sprite::Update();

	_velocity = { 0,0 };
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
		
	raywrp::DrawRectangleV(_position, {50,50}, BLEU);
	
}
