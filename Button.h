#pragma once
#include "Vec2.h"
#include <string>
#include "RaylibWrapper.h"
#include "Couleur.h"
class Button
{
	private :
		Vec2<float> _position;
		Vec2<float> _dimensions;
		Couleur _color;
		std::string _text;
		Vec2<float> _textPosition;
		Couleur _textColor;
		int _fontSize;
		bool _isFocused;
		Sound _selectEffect;

	public :
		Button();
		void Init(Vec2<float> position, Vec2<float> dimensions, std::string text, Couleur color);
		void Update(Vec2<float> mousePos);
		void Draw();
		bool IsClicked();
		void SetTextColor(Couleur color);
};
