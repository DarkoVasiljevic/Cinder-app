#include "Shape.h"

Shape::Shape(float X = 0.0, float Y = 0.0, float R = 0.0, float G = 0.0, float B = 0.0)
{
	_location.X = X;
	_location.Y = Y;
	_color.R = R;
	_color.G = G;
	_color.B = B;
}

Shape::Shape(float X, float Y)
{
	_location.X = X;
	_location.Y = Y;

	//Rand::randSeed(time(nullptr));
	_color.R = Rand::randFloat();
	_color.G = Rand::randFloat();
	_color.B = Rand::randFloat();

	_direction = Rand::randVec2();
	_velocity = Rand::randVec2()*5.0f;
}

std::string Shape::TypeOfShape(Enum_Shape e)
{
	switch (e)
	{
	case Enum_Shape::CIRCLE:
		return "Circle";
	case Enum_Shape::SQUARE:
		return "Square";
	case Enum_Shape::RECTANGLE:
		return "Rectangle";
	default:
		return "Unknown shape";
	}
}

Shape::Location_t Shape::GetLocation() { return _location; }
void Shape::SetLocation(Location_t& l) { _location = l; }

Shape::Color_t Shape::GetColor() { return _color; }
void Shape::SetColor(Color_t& c) { _color = c; }

unsigned Shape::_id = 0;