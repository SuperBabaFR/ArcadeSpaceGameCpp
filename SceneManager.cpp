#include "SceneManager.h"
#include "settings.h"

SceneManager::SceneManager() : _background(stg::screenWidth, 20, 100)
{
	_currentScene = &_menu;
	Init();
}

void SceneManager::Init()
{
	_background.Init();
	_currentScene->Init();
}

void SceneManager::SwitchScene(Scene& scene)
{
	_currentScene = &scene;
	_currentScene->Init();
}

void SceneManager::Update()
{
	int scoreDiff{ 0 };
	
	
	SceneID currentSceneName = _currentScene->GetSceneName();

	if (currentSceneName != Jeu)
		_background.Update({ stg::screenWidth / 2.0f , stg::screenHeight / 2.0f });

	_currentScene->Update();

	switch (currentSceneName)
	{
	case Menu:
		// Commencer une partie
		if (_menu.IsSceneSwitching())
			SwitchScene(_jeu);

		break;
	case Jeu:
		// Mettre le jeu en pause
		if (IsKeyPressed(KEY_ESCAPE))
			SwitchScene(_pause);

		// Vérifier si quelqu'un a gagné

		// _gameover.SetScore(scoreDiff);
		// SwitchScene(_gameover);

		break;
	case Pause:
		if (_pause.IsSceneSwitching() == Nothing)
			break;

		if (_pause.IsSceneSwitching() == Resume) // Reprendre la partie
			_currentScene = &_jeu;
		
		else if (_pause.IsSceneSwitching() == Reset) // Recommencer la partie
			SwitchScene(_jeu);

		else if (_pause.IsSceneSwitching() == Quit) // Retourner au menu
			SwitchScene(_menu);

		break;
	case PartieFinie:
		if (_gameover.IsSceneSwitching() == Nothing)
			break;

		if (_gameover.IsSceneSwitching() == Reset) // Reprendre la partie
			SwitchScene(_jeu);

		else if (_gameover.IsSceneSwitching() == Quit) // Recommencer la partie
			SwitchScene(_menu);
		break;
	default:
		break;
	}
}

void SceneManager::Draw()
{
	ClearBackground(BLACK);
	SceneID currentSceneName = _currentScene->GetSceneName();
	
	if (currentSceneName != Jeu)
		_background.Draw();

	_currentScene->Draw();
}

//if (_jeu.playerDeath() > 0) // Joueur 1 gagne
//{
//	
//}
//else if (_jeu.playerDeath() < 0) // Joueur 2 gagne
//{

//}