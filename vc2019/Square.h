#pragma once

#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "Shape.h"

class Square : public Shape {

public:

	Square() = default;
	~Square() = default;

	Square(float, float, float, float, float, float);
	Square(float, float);

	Shape* Copy() const override;
	void Update() override;
	void Draw() override;
	void IsClickingOnShape(vec2) override;
	void UpdateShapeWASD(bool, bool, bool, bool) override;
	std::string Type() override;

	void UpdateDirection(int, int);

	float GetSize();
	void SetSize(float);
	Rectf GetBounds();

private:
	float _size;
};

#endif
