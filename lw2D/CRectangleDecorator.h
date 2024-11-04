#pragma once
#include "CShapeDecorator.h"


class CRectangleDecorator : public CShapeDecorator
{
public:
    CRectangleDecorator(std::shared_ptr<IShape> shape);

    virtual ~CRectangleDecorator() = default;

protected:
    float CalculateArea() const override;
    float CalculatePerimeter() const override;

};

