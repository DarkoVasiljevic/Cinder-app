#pragma once

#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include "cinder/app/App.h"
#include "cinder/app/FileDropEvent.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderImGui.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace gl;

#include <string>
#include <vector>
#include <set>
#include <time.h> 
#include <typeinfo>

class Shape {

public:

	Shape() = default;
	virtual ~Shape() = default;

	Shape(float, float, float, float, float);
	Shape(float, float);

	virtual Shape* Copy() const = 0;

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void IsClickingOnShape(vec2) = 0;
	virtual void UpdateShapeWASD(bool, bool, bool, bool) = 0;
	virtual std::string Type() = 0;

	enum class Enum_Shape { CIRCLE, SQUARE, RECTANGLE };
	std::string TypeOfShape(Enum_Shape);

public:

	typedef struct { float X, Y; } Location_t;
	typedef struct { float R, G, B; } Color_t;

	Location_t GetLocation();
	void SetLocation(Location_t&);

	Color_t GetColor();
	void SetColor(Color_t&);

	bool _forDelete = false;
	bool _animateLast = false;

	static unsigned _id;

protected:
	Location_t _location;
	Color_t _color;

	vec2 _direction;
	vec2 _velocity;
};

#endif





