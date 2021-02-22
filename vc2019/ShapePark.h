#pragma once

#ifndef __SHAPE_PARK_HPP__
#define __SHAPE_PARK_HPP__

#include "Shape.h"

#include <map>
#include <algorithm> 

class ShapePark {

public:

	ShapePark() = default;
	~ShapePark();

	ShapePark(const ShapePark&);
	ShapePark& operator=(const ShapePark&);

	void AddShape(Shape*);
	void RemoveShape();

	void UpdateShapeList();
	void DrawShapeList();
	void IsClickingOnShapes(vec2);
	void UpdateShapeListWASD(bool, bool, bool, bool);

	std::map<unsigned, Shape*> _shapeList;
};

#endif
