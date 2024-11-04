#pragma once
#include "CShapeDecorator.h"


class CCircleDecorator : public CShapeDecorator 
{
public:
    CCircleDecorator(std::shared_ptr<IShape> shape);

    virtual ~CCircleDecorator() = default;

protected:
    float CalculateArea() const override;
    float CalculatePerimeter() const override;

};
