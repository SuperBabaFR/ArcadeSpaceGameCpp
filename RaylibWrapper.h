#pragma once
#include "Vec2.h"
#include "Cam2D.h"
#include "Couleur.h"
#include "Rect.h"
#include "raylib.h"
#include <string>

namespace raywrp {
	void DrawRectangleV(Vec2<float> position, Vec2<float> size, Couleur color);
	void DrawCircleV(Vec2<float> center, float radius, Couleur color);
	bool CheckCollisionCircleRec(Vec2<float> center, float radius, Rect rec);
	bool CheckCollisionPointRec(Vec2<float> point, Rect rec);
	int MesureText(std::string text, int fontSize);
	void DrawTextV(std::string text, Vec2<float> position, int fontSize, Couleur color);
	void DrawRectangleLinesV(Vec2<float> position, Vec2<float> size, Couleur color);
	Color CouleurtoColor(Couleur couleur);

	// Cam
	void BeginDraw2D(Cam2D cam);
	void EndDraw2D();

	//bool IsSongPlaying(Sound song);
	//void PlaySong(Sound song);

	Vec2<float> GetMousePositionV();
	float GetDeltaTime();

	// Math
	float Vec2AngleDeg(Vec2<float> v1, Vec2<float> v2);
}

