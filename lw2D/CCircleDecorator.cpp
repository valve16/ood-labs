#include "CCircleDecorator.h"
#include "CCircle.h"

CCircleDecorator::CCircleDecorator(std::shared_ptr<IShape> shape)
	: CShapeDecorator(std::move(shape))
{
	SetArea();
	SetPerimeter();
};

float CCircleDecorator::CalculateArea() const
{
    auto circle = std::dynamic_pointer_cast<CCircle>(m_shape);
    float radius = circle->GetRadius();
    return static_cast<float>(M_PI) * radius * radius;
}

float CCircleDecorator::CalculatePerimeter() const
{
    auto circle = std::dynamic_pointer_cast<CCircle>(m_shape);
    float radius = circle->GetRadius();
    return 2 * static_cast<float>(M_PI) * radius;
}

