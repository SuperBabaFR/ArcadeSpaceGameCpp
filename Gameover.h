#pragma once
#include "Button.h"
#include "Scene.h"
#include <iostream>

class Gameover : public Scene
{
private:
	Button _rematch;
	Button _quit;
	int _score;
	std::string _screenText;
public:
	// Constructeur
	Gameover();
	// Méthodes override
	void Init() override;
	void Update() override;
	void Draw() override;
	int IsSceneSwitching();
	// Méthodes
	void SetScore(int score);
};

