#pragma once
#include <list>
#include "Sprite.h"

enum SceneID {
	Menu,
	Jeu,
	Pause,
	PartieFinie
};

enum MenuAction {
	Nothing,
	Resume,
	Reset,
	Quit
};

class Scene
{
	public:
		// Constructeur
		Scene(SceneID scene);
		// Supprime la copie de l'objet Game
		Scene(const Scene& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		// Méthodes virtuelles
		void virtual Init();
		void virtual Update();
		void virtual Draw();
		// Destructeur
		~Scene();
		// Getters
		SceneID GetSceneName();
	protected:
		SceneID _sceneName;
		std::list<Sprite*> _listSprite;
};

