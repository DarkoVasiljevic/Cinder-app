#include "Square.h"

Square::Square(float size = 0.0, float X = 0.0, float Y = 0.0, float R = 0.0, float G = 0.0, float B = 0.0)
	: _size(size), Shape(X, Y, R, G, B)
{}

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
}

void Square::IsClickingOnShape(vec2)
{
}

void Square::UpdateShapeWASD(bool, bool, bool, bool)
{
}

float Square::GetSize() { return _size; }
void Square::SetSize(float s) { _size = s; }
