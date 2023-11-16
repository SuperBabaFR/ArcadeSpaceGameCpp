#include "StarryBackground.h"
#include "settings.h"

StarryBackground::StarryBackground(int amount, float size, float maxSpeed) : _starAmount(amount), _maxSpeed(maxSpeed), _maxSize(size)
{
}

int randomNumber2(int minimum, int maximum)
{
	int valeur{ 0 };

	valeur = std::rand() % maximum;

	if (valeur < minimum)
		valeur = minimum;

	return valeur;
}

void StarryBackground::Init()
{
	_stars.clear();
	
	for (int i = 0; i < _starAmount; i++)
	{
		Vec2<float> pos{ float(randomNumber2(0, stg::screenWidth)), float(randomNumber2(0, stg::screenHeight)) };
		float speed = randomNumber2(10, int(_maxSpeed)) / 10.0f;
		float rayon = randomNumber2(7, int(_maxSize)) / 10.0f;
		
		Star newStar{ pos, speed, rayon };
		_stars.push_back(newStar);
	}
}

void StarryBackground::Update()
{
	for (Star &star : _stars)
	{
		star.Update();
	}
}

void StarryBackground::Draw()
{
	for (const Star &star : _stars)
	{
		star.Draw();
	}
}
