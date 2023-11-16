#pragma once
#include "Scene.h"
#include "Button.h"
class PauseMenu : public Scene
{
	private:
		Button _resume;
		Button _reset;
		Button _quit;
	public:
		// Constructeur
		PauseMenu();
		// Méthodes override
		void Init() override;
		void Update() override;
		void Draw() override;
		int IsSceneSwitching();
};

