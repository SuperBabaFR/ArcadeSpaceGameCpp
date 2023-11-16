#include "Cam2D.h"

Cam2D::Cam2D(Vec2<float> offset, Vec2<float> target, float rotation, float zoom)
	: _offset(offset), _target(target), _rotation(rotation), _zoom(zoom)
{
}

Cam2D::Cam2D() : _offset({ 0.0f, 0.0f }), _target({ 0.0f, 0.0f }), _rotation(0.0f), _zoom(1.0f)
{
}


void Cam2D::SetOffset(Vec2<float> offset)
{
	_offset = offset;
}

void Cam2D::SetTarget(Vec2<float> target)
{
	_target = target;
}

Vec2<float> Cam2D::GetOffset()
{
	return _offset;
}

Vec2<float> Cam2D::GetTarget()
{
	return _target;
}

float Cam2D::GetRotation()
{
	return _rotation;
}

float Cam2D::GetZoom()
{
	return _zoom;
}
