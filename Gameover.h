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
	// M�thodes override
	void Init() override;
	void Update() override;
	void Draw() override;
	int IsSceneSwitching();
	// M�thodes
	void SetScore(int score);
};

