#include "RaylibWrapper.h"
#include "Vec2.h"
#include "Cam2D.h"
#include "raylib.h"
#include "settings.h"
#include <string>
#include <assert.h>

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

float raywrp::Vec2AngleDeg(Vec2<float> v1, Vec2<float> v2)
{
	float result = atan2f(v2.GetY() - v1.GetY(), v2.GetX() - v1.GetX()) / PI * 180;

	return (result > 0)? result : 180 + abs(result);
}
