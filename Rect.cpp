#include "Rect.h"

Rect::Rect(float x, float y, float height, float width) :
	_x(x), _y(y), _width(width), _height(height)
{}

float Rect::GetX()
{
	return _x;
}

float Rect::GetY()
{
	return _y;
}

float Rect::GetHeight()
{
	return _width;
}

float Rect::GetWidth()
{
	return _height;
}
