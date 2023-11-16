#pragma once
#include "Vec2.h"
#include "Couleur.h"

class Star
{
	private :
		Vec2<float> _position;
		float _speed;
		float _rayon;
	public :
		Star(Vec2<float> position, float speed, float rayon);
		void Update(); //Vec2<float> center);
		void Draw() const;
};

