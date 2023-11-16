#include "Star.h"
#include "settings.h"
#include "RaylibWrapper.h"

Star::Star(Vec2<float> position, float speed, float rayon) : _position(position), _speed(speed), _rayon(rayon)
{
}

void Star::Update() //Vec2<float> center)
{
	_position.SetY(_position.GetY() + _speed * raywrp::GetDeltaTime());

	if (_position.GetY() + _rayon >= stg::screenHeight)
	{
		_position.SetY(- _rayon);
	}

}

void Star::Draw() const
{
	raywrp::DrawCircleV(_position, _rayon, BLANC);
}
