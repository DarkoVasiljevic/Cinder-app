#include "Circle.h"

Circle::Circle(const Circle& c)
	: _radius(c._radius), Shape(c._location.X, c._location.Y, c._color.R, c._color.G, c._color.B)
{}

Circle::Circle(float radius = 0.0, float X = 0.0, float Y = 0.0, float R = 0.0, float G = 0.0, float B = 0.0)
	: _radius(radius), Shape(X, Y, R, G, B)
{}

Circle::Circle(float X, float Y)
	: Shape(X, Y)
{
	_radius = 10 + Rand::randFloat(getWindowWidth() / 15.0f);
}

Circle& Circle::operator=(Circle& c) {

	auto tmp(c);

	std::swap(_radius, c._radius);
	std::swap(_location.X, c._location.X);
	std::swap(_location.Y, c._location.Y);

	std::swap(_color.R, c._color.R);
	std::swap(_color.G, c._color.G);
	std::swap(_color.B, c._color.B);

	return *this;
}

Shape* Circle::Copy() const { return new Circle(*this); }

std::string Circle::Type()
{
	return TypeOfShape(Enum_Shape::CIRCLE);
}

void Circle::Update()
{
	_location.X += cos(_direction.x) * _velocity.x;
	_location.Y += sin(_direction.y) * _velocity.y;

	if (_location.X - _radius < 205 || _location.X + _radius + 205 > getWindowSize().x) 
	{
		_velocity.x *= -1.0f;
	}

	if (_location.Y - _radius < 50 || _location.Y + _radius + 100 > getWindowSize().y)
	{
		_velocity.y *= -1.0f;
	}
}

void Circle::Draw()
{
	gl::color(Color(GetColor().R, GetColor().G, GetColor().B));
	gl::drawSolidCircle(vec2(GetLocation().X, GetLocation().Y), GetRadius());
}

float Circle::GetRadius() { return _radius; }
void Circle::SetRadius(float r) { _radius = r; }

void Circle::IsClickingOnShape(vec2 mousePos)
{
	_forDelete = (powf((GetLocation().X - mousePos.x), 2) + powf((GetLocation().Y - mousePos.y), 2)) <= powf(GetRadius(), 2);
}

void Circle::UpdateDirection(int dirX, int dirY)
{
	float speed = 2.5;

	_location.X += dirX * speed;
	_location.Y += dirY * speed;
}

void Circle::UpdateShapeWASD(bool w, bool a, bool s, bool d)
{
	if (w)		{ UpdateDirection(0, -1); }	
	else if (a) { UpdateDirection(-1, 0); }
	else if (s) { UpdateDirection(0, 1); }
	else if (d) { UpdateDirection(1, 0); }
}

