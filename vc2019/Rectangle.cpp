#include "Rectangle.h"

Rectangle::Rectangle(float X, float Y, float R, float G, float B, float width = 0.0, float height = 0.0)
	: _width(width), _height(height), Shape(X, Y, R, G, B)
{}

Rectangle::Rectangle(float X, float Y)
	: Shape(X, Y)
{
	_height = 15 + Rand::randFloat(getWindowWidth() / 15.0f);
	_width = 15 + Rand::randFloat(getWindowWidth() / 15.0f);
}

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
	gl::color(Color(GetColor().R, GetColor().G, GetColor().B));
	gl::drawSolidRect(Rectf(GetBounds()));
}

void Rectangle::IsClickingOnShape(vec2 pos)
{
	Rectf bounds = GetBounds();
	_forDelete = bounds.distance(pos) == 0;
}

void Rectangle::UpdateShapeWASD(bool, bool, bool, bool)
{
}

Rectf Rectangle::GetBounds()
{
	float tx = GetWidth() / 2.0f;
	float ty = GetHeight() / 2.0f;

	float x1 = GetLocation().X - tx;
	float y1 = GetLocation().Y - ty;
	float x2 = GetLocation().X + tx;
	float y2 = GetLocation().Y + ty;

	return Rectf(x1, y1, x2, y2);
}

float Rectangle::GetWidth() { return _width; }
void Rectangle::SetWidth(float w) { _width = w; }

float Rectangle::GetHeight() { return _height; }
void Rectangle::SetHeight(float h) { _height = h; }