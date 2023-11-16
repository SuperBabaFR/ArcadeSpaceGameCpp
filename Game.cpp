#include <cassert>
#include "Game.h"
#include "raylib.h"
#include "RaylibWrapper.h"
#include "SceneManager.h"

Game::Game(int width, int height, std::string title)
{
	assert(!GetWindowHandle());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(GetMonitorRefreshRate(0));
}

void Game::Init()
{
	// Scene Manager
	_sceneManager.Init();
}

Game::~Game() noexcept
{
	assert(GetWindowHandle());
	CloseAudioDevice();
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE);
}

void Game::Tick()
{
	Update();
	BeginDrawing();

	// Main Draw
	Draw();

	EndDrawing();
}

void Game::Update()
{
	// Mise a jour du manager de scènes
	_sceneManager.Update();
}

void Game::Draw()
{	
	// Dessine les scènes
	_sceneManager.Draw();
}
