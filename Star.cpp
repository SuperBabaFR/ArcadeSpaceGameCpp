#include "Star.h"
#include "settings.h"
#include "RaylibWrapper.h"

Star::Star(Vec2<float> position, float speed, float rayon) : _position(position), _speed(speed), _rayon(rayon)
{
}

void Star::Update(Vec2<float> center)
{
	
	// _position.SetY(_position.GetY() + _speed * raywrp::GetDeltaTime());
	// _position.SetX(_position.GetX() + _speed * raywrp::GetDeltaTime());

	if (_position.GetY() + _rayon >= center.GetY() + stg::screenHeight / 2.0f) // BAS
	{
		_position.SetY(center.GetY() - stg::screenHeight / 2.0f - _rayon);
	}
	else if (_position.GetY() - _rayon <= center.GetY() - stg::screenHeight / 2.0f) // HAUT
	{
		_position.SetY(center.GetY() + stg::screenHeight / 2.0f + _rayon);
	}

	if (_position.GetX() + _rayon >= center.GetX() + stg::screenWidth / 2.0f) // DROITE
	{
		_position.SetX(center.GetX() - stg::screenWidth / 2.0f + _rayon);
	}
	else if (_position.GetX() - _rayon <= center.GetX() - stg::screenWidth / 2.0f) // GAUCHE
	{
		_position.SetX(center.GetX() + stg::screenWidth / 2.0f - _rayon);
	}

}

void Star::Draw() const
{
	raywrp::DrawCircleV(_position, _rayon, BLANC);
}
