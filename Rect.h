#pragma once
class Rect
{
private :
	float _x;
	float _y;
	float _height;
	float _width;
public :
	// Constructeur
	Rect(float x, float y, float height, float width);
	// Accesseurs
	float GetX();
	float GetY();
	float GetHeight();
	float GetWidth();
	// Mutateurs
};

