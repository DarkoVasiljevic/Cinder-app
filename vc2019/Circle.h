#pragma once

#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "Shape.h"

class Circle : public Shape {

public:

	Circle() = default;
	~Circle() = default;

	Circle(float, float, float, float, float, float);
	Circle(float, float);

	Circle(const Circle&);
	Circle& operator=(Circle&);

	Shape* Copy() const override;

	void Update() override;
	void Draw() override;
	void IsClickingOnShape(vec2) override;
	void UpdateShapeWASD(bool, bool, bool, bool) override;
	std::string Type() override;
	void UpdateDirection(int, int);

	float GetRadius();
	void SetRadius(float);

private:
	float _radius;
	
};

#endif
