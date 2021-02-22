#include "Rectangle.h"

Rectangle::Rectangle(float X, float Y, float R, float G, float B, float width = 0.0, float height = 0.0)
	: _width(width), _height(height), Shape(X, Y, R, G, B)
{}

Shape* Rectangle::Copy() const { return new Rectangle(*this); }

std::string Rectangle::Type()
{
	return TypeOfShape(Enum_Shape::RECTANGLE);
}

void Rectangle::Update()
{
}

void Rectangle::Draw()
{
}

void Rectangle::IsClickingOnShape(vec2)
{
}

void Rectangle::UpdateShapeWASD(bool, bool, bool, bool)
{
}

float Rectangle::GetWidth() { return _width; }
void Rectangle::SetWidth(float w) { _width = w; }

float Rectangle::GetHeight() { return _height; }
void Rectangle::SetHeight(float h) { _height = h; }