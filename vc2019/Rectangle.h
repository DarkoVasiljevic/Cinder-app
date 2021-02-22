#pragma once

#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Shape.h"

class Rectangle : public Shape {

public:

	Rectangle() = default;
	~Rectangle() = default;

	Rectangle(float, float, float, float, float, float, float);

	Shape* Copy() const override;
	void Update() override;
	void Draw() override;
	void IsClickingOnShape(vec2) override;
	void UpdateShapeWASD(bool, bool, bool, bool) override;
	std::string Type() override;

	float GetWidth();
	void SetWidth(float);

	float GetHeight();
	void SetHeight(float);

private:
	float _width;
	float _height;

};

#endif
