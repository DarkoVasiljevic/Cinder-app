#include "Square.h"

Square::Square(float size = 0.0, float X = 0.0, float Y = 0.0, float R = 0.0, float G = 0.0, float B = 0.0)
	: _size(size), Shape(X, Y, R, G, B)
{}

Square::Square(float X, float Y)
	: Shape(X, Y)
{
	_size = 15 + Rand::randFloat(getWindowWidth() / 15.0f);
}

Shape* Square::Copy() const { return new Square(*this); }

std::string Square::Type()
{
	return TypeOfShape(Enum_Shape::SQUARE);
}

void Square::Update()
{
}

void Square::Draw()
{
	gl::color(Color(GetColor().R, GetColor().G, GetColor().B));
	gl::drawSolidRect(Rectf(GetBounds()));
}

void Square::IsClickingOnShape(vec2 pos)
{
	Rectf bounds = GetBounds();
	_forDelete = bounds.distance(pos) == 0;
}

void Square::UpdateShapeWASD(bool, bool, bool, bool)
{
}

Rectf Square::GetBounds()
{
	float tx = GetSize() / 2.0f;
	float ty = GetSize() / 2.0f;

	float x1 = GetLocation().X - tx;
	float y1 = GetLocation().Y - ty;
	float x2 = GetLocation().X + tx;
	float y2 = GetLocation().Y + ty;

	return Rectf(x1, y1, x2, y2);
}

float Square::GetSize() { return _size; }
void Square::SetSize(float s) { _size = s; }
