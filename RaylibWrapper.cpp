#include "RaylibWrapper.h"
#include <assert.h>
#include <string>
#include <cmath>
#include "Vec2.h"
#include "Cam2D.h"
#include "raylib.h"
#include "settings.h"

void raywrp::DrawRectangleV(Vec2<float> position, Vec2<float> size, Couleur color)
{
	DrawRectangleV(Vector2{ position.GetX(), position.GetY() }, Vector2{ size.GetX(), size.GetY() }, CouleurtoColor(color));
}

void raywrp::DrawCircleV(Vec2<float> center, float radius, Couleur color)
{
	DrawCircleV(Vector2{ center.GetX(), center.GetY() }, radius, CouleurtoColor(color));
}

bool raywrp::CheckCollisionCircleRec(Vec2<float> center, float radius, Rect rec)
{
	Rectangle rect{ rec.GetX(), rec.GetY(), rec.GetWidth(), rec.GetHeight() };
	return CheckCollisionCircleRec(Vector2{ center.GetX(), center.GetY() }, radius, rect);
}

bool raywrp::CheckCollisionPointRec(Vec2<float> point, Rect rec)
{
	Rectangle rect{ rec.GetX(), rec.GetY(), rec.GetWidth(), rec.GetHeight() };
	return CheckCollisionPointRec(Vector2{ point.GetX(), point.GetY() }, rect);
}

void raywrp::DrawTextV(std::string text, Vec2<float> position, int fontSize, Couleur color)
{
	int MiddleOfText = MeasureText(text.c_str(), fontSize)/2;
	if (position.GetX() == -69)
	{
		int MiddleScreenX = stg::screenWidth / 2;
		position.SetX(static_cast<float>(MiddleScreenX - MiddleOfText));
	}

	if (position.GetY() == -69)
	{
		int MiddleScreenY = stg::screenHeight / 2;
		position.SetY(static_cast<float>(MiddleScreenY - fontSize/2));
	}
	
	DrawText(text.c_str(), static_cast<int>(position.GetX()), static_cast<int>(position.GetY()), fontSize, CouleurtoColor(color));
}

void raywrp::DrawRectangleLinesV(Vec2<float> position, Vec2<float> size, Couleur color)
{
	DrawRectangleLines(static_cast<int>(position.GetX()), static_cast<int>(position.GetY()), static_cast<int>(size.GetX()), static_cast<int>(size.GetY()), CouleurtoColor(color));
}

void raywrp::DrawContourCercle(Vec2<float> position, float radius, Couleur color)
{
	DrawCircleLines(position.GetX(), position.GetY(), radius, CouleurtoColor(color));
}

Color raywrp::CouleurtoColor(Couleur couleur)
{
	return Color{ couleur.GetRed(), couleur.GetGreen(), couleur.GetBlue(), couleur.GetAlpha() };
}

void raywrp::BeginDraw2D(Cam2D cam)
{
	
	Camera2D camera = { 0 };
	camera.offset = { cam.GetOffset().GetX(), cam.GetOffset().GetY() };
	camera.target = { cam.GetTarget().GetX(), cam.GetTarget().GetY() };
	camera.rotation = cam.GetRotation();
	camera.zoom = cam.GetZoom();

	BeginMode2D(camera);
}

void raywrp::EndDraw2D()
{
	EndMode2D();
}

void raywrp::DrawRectangle(Rect rec, Vec2<float> origin, float rotation, Couleur color)
{
	Rectangle rect{ rec.GetX(), rec.GetY(), rec.GetWidth(), rec.GetHeight() };
	
	DrawRectanglePro(rect, { origin.GetX(), origin.GetY() }, rotation, CouleurtoColor(color));
}

Vec2<float> raywrp::GetMousePositionV()
{
	Vector2 mousePosition(GetMousePosition());

	return Vec2<float> { mousePosition.x, mousePosition.y };
}

int raywrp::MesureText(std::string text, int fontSize)
{
	return MeasureText(text.c_str(), fontSize);
}

float raywrp::GetDeltaTime()
{	
	return GetFrameTime();
}

Vec2<float> raywrp::GetScreenToWorld2DPoint(Vec2<float> point, Cam2D cam)
{
	Camera2D camera = { 0 };
	camera.offset = { cam.GetOffset().GetX(), cam.GetOffset().GetY() };
	camera.target = { cam.GetTarget().GetX(), cam.GetTarget().GetY() };
	camera.rotation = cam.GetRotation();
	camera.zoom = cam.GetZoom();
	
	Vector2 retour = GetScreenToWorld2D({ point.GetX(), point.GetY() }, camera);

	return {retour.x, retour.y};
}

float raywrp::Vec2AngleDeg(Vec2<float> v1, Vec2<float> v2)
{
	Vec2<float> direction{ v2.GetX() - v1.GetX(), v2.GetY() - v1.GetY() };

	float angleRadians = std::atan2(direction.GetY(), direction.GetX());

	// Convertir l'angle en degrés
	float angleDegrees = angleRadians * RAD2DEG;
	
	// Assurer que l'angle est dans la plage de 0 à 360 degrés
	if (angleDegrees < 0)
		angleDegrees += 360;

	return angleDegrees;
}
