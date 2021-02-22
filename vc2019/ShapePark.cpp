#include "ShapePark.h"

ShapePark::~ShapePark()
{
    std::for_each(_shapeList.begin(), _shapeList.end(), 
        [](std::pair<unsigned, Shape*> a) { delete a.second; });

    _shapeList.clear();
}

ShapePark::ShapePark(const ShapePark& other)
    //: _shapeList(other._shapeList)
{
    _shapeList.insert(other._shapeList.begin(), other._shapeList.end());
}

ShapePark& ShapePark::operator=(const ShapePark& v) {

    auto tmp(v);

    std::swap(_shapeList, tmp._shapeList);

    return *this;
}

void ShapePark::AddShape(Shape* shape)
{
    if (_shapeList.size() > 0)
        _shapeList.rbegin()->second->_animateLast = false;
       
    shape->_animateLast = true;
    _shapeList.insert(std::make_pair(Shape::_id++, shape));
}

void ShapePark::RemoveShape()
{
    unsigned pos = -1;
    for (auto it = _shapeList.rbegin(); it != _shapeList.rend(); it++)
    {
        if (it->second->_forDelete)
            _shapeList.erase(it->first);
    }

    std::for_each(_shapeList.begin(), _shapeList.end(),
        [](std::pair<unsigned, Shape*> a) { a.second->_forDelete = false; });
}

void ShapePark::UpdateShapeList()
{
    std::for_each(_shapeList.begin(), _shapeList.end(),
        [](std::pair<unsigned, Shape*> a) { a.second->Update(); });
}

void ShapePark::DrawShapeList()
{
    std::for_each(_shapeList.begin(), _shapeList.end(),
        [](std::pair<unsigned, Shape*> a) { a.second->Draw(); });
}

void ShapePark::IsClickingOnShapes(vec2 mousePos)
{
    std::for_each(_shapeList.begin(), _shapeList.end(),
        [&mousePos](std::pair<unsigned, Shape*> a) { a.second->IsClickingOnShape(mousePos); });
}

void ShapePark::UpdateShapeListWASD(bool w, bool a, bool s, bool d)
{
    std::for_each(_shapeList.begin(), _shapeList.end(), [w, a, s, d](std::pair<unsigned, Shape*> shape)
        { if (shape.second->_animateLast) shape.second->UpdateShapeWASD(w, a, s, d); });
}