#include "Button.h"
#include <iostream>
#include "RaylibWrapper.h"


Button::Button()
{
	_position = Vec2<float>(0, 0);
	_dimensions = Vec2<float>(150, 75);
	_color = ROUGE;
	_textColor = BLANC;
	_text = "Maco";
	_fontSize = 30;
	_isFocused = false;

	int textSize = raywrp::MesureText(_text, _fontSize);
	float xOffset = (_dimensions.GetX() - textSize) / 2.0f;
	float yOffset = (_dimensions.GetY() - _fontSize) / 2.0f;

	std::cout << "text : " << _text << "\n";
	std::cout << "textSize : " << textSize << "\n";
	std::cout << "xOffset : " << xOffset << ", yOffset : " << yOffset << "\n";

	_textPosition.SetX(_position.GetX() + xOffset);
	_textPosition.SetY(_position.GetY() + yOffset);

}

void Button::Init(Vec2<float> position, Vec2<float> dimensions, std::string text, Couleur color)
{
	_text = text;
	_color = color;
	_dimensions = dimensions;
	
	_position = position - dimensions / 2.0f;
	
	_textColor = BLANC;

	_fontSize = 30;
	int textSize = raywrp::MesureText(_text, _fontSize);
	float xOffset = (dimensions.GetX() - textSize) / 2.0f;
	float yOffset = (dimensions.GetY() - _fontSize) / 2.0f;

	std::cout << "text : " << text << "\n";
	std::cout << "textSize : " << textSize << "\n";
	std::cout << "xOffset : " << xOffset << ", yOffset : " << yOffset << "\n";

	_textPosition.SetX(_position.GetX() + xOffset);
	_textPosition.SetY(_position.GetY() + yOffset);

	_isFocused = false;

	// Sound
	_selectEffect = LoadSound("Ressources\\select.ogg");
}

bool Button::IsClicked()
{
	if (!_isFocused)
	{
		return false;
	}
	
	return IsMouseButtonReleased(0);
}

void Button::SetTextColor(Couleur color)
{
	_textColor = color;
}


void Button::Update(Vec2<float> mousePos)
{
	Rect button(
		_position.GetX(),
		_position.GetY(),
		_dimensions.GetX(),
		_dimensions.GetY());

	bool isMouseIn = raywrp::CheckCollisionPointRec(mousePos, button);

	if (!_isFocused && isMouseIn)
		PlaySound(_selectEffect);

	_isFocused = isMouseIn;
}


void Button::Draw()
{
	if (_isFocused)
	{
		raywrp::DrawRectangleV(_position, _dimensions, _color);
	}
	else 
	{
		raywrp::DrawRectangleLinesV(_position, _dimensions, _color);
	}
	raywrp::DrawTextV(_text, _textPosition, _fontSize, _textColor);
}