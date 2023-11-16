#pragma once
#include <iostream>
#include "SceneManager.h"

class Game
{
private:
	SceneManager _sceneManager;
	void Update();
	void Draw();
public:
	// Constructeur
	Game(int width, int height, std::string title);
	void Init();
	// Destructeur
	~Game() noexcept;
	// Supprime la copie de l'objet Game
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;

	bool GameShouldClose() const;

	void Tick();
};

