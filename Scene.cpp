#include "Scene.h"

Scene::Scene(SceneID scene) : _sceneName(scene)
{
}

void Scene::Init()
{

}

void Scene::Update()
{

}

void Scene::Draw()
{
	// Fond 
	// ClearBackground(BLACK);
}

SceneID Scene::GetSceneName()
{
	return _sceneName;
}

Scene::~Scene()
{
	//for (auto& sprite : _listSprite)
	//{
	//	delete sprite;
	//}
}