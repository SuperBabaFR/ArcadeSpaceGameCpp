#pragma once
#include "Scene.h"
#include "Button.h"
class MenuPrincipal : public Scene
{
	private:
		Button _play;
	public:
		// Constructeur
		MenuPrincipal();
		// Méthodes override
		void Init() override;
		void Update() override;
		void Draw() override;
		bool IsSceneSwitching();
};

