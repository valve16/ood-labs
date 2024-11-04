#pragma once
#include "CShapeDecorator.h"

class CTriangleDecorator : public CShapeDecorator
{
public:
    CTriangleDecorator(std::shared_ptr<IShape> shape);

    virtual ~CTriangleDecorator() = default;

protected:
    float CalculateArea() const override;
    float CalculatePerimeter() const override;

};
