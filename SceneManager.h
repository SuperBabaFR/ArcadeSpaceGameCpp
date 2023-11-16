#pragma once
#include "StarryBackground.h"
#include "Scene.h"
#include "MenuPrincipal.h"
#include "Gameplay.h"
#include "PauseMenu.h"
#include "Gameover.h"

class SceneManager
{
	private :
		MenuPrincipal _menu;
		Gameplay _jeu;
		PauseMenu _pause;
		Gameover _gameover;
		Scene* _currentScene;
		StarryBackground _background;
	public :
		SceneManager();
		void Init();
		void SwitchScene(Scene& scene);
		void Update();
		void Draw();
};

