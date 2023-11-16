#pragma once
#include "vector"
#include "Star.h"
class StarryBackground
{
	private :
		int _starAmount;
		float _maxSize;
		float _maxSpeed;
		std::vector<Star> _stars;
	public : 
		StarryBackground(int amount, float size, float maxSpeed);
		void Init();
		void Update();
		void Draw();
};

