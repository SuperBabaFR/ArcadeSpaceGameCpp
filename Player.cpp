#include "Player.h"
#include "RaylibWrapper.h"
#include "settings.h"
#include <numbers>

Player::Player()
{	
	_speed = 500;
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
		_velocity.SetY(_velocity.GetY() - _speed * raywrp::GetDeltaTime());
	else if (IsKeyDown(KEY_S))
		_velocity.SetY(_velocity.GetY() + _speed * raywrp::GetDeltaTime());

	if (IsKeyDown(KEY_A))
		_velocity.SetX(_velocity.GetX() - _speed * raywrp::GetDeltaTime());
	else if (IsKeyDown(KEY_D))
		_velocity.SetX(_velocity.GetX() + _speed * raywrp::GetDeltaTime());

	_rotation = raywrp::Vec2AngleDeg(raywrp::GetMousePositionV(), _position);
	


	//if (IsKeyReleased(KEY_E))
	//	_rotation += 10;

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
	std::string text{ "Rotation : " };
	text += std::to_string(_rotation);
	raywrp::DrawTextV(text, { 10,0 }, 20, ROUGE);
	//raywrp::DrawRectangleV(_position, {50,50}, BLEU);
	DrawPoly({ _position.GetX(), _position.GetY() }, 3, 30, _rotation, BLUE);
}
