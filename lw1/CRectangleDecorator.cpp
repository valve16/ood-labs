#include "CRectangleDecorator.h"
#include "CRectangle.h"

CRectangleDecorator::CRectangleDecorator(std::shared_ptr<IShape> shape)
    : CShapeDecorator(std::move(shape))
{
    SetArea();
    SetPerimeter();
};

float CRectangleDecorator::CalculateArea() const
{
    auto rectangle = std::dynamic_pointer_cast<CRectangle>(m_shape);
    float height = rectangle->GetHeight();
    float width = rectangle->GetWidth();
    return height * width;
}

float CRectangleDecorator::CalculatePerimeter() const
{
    auto rectangle = std::dynamic_pointer_cast<CRectangle>(m_shape);
    float height = rectangle->GetHeight();
    float width = rectangle->GetWidth();
    return 2 * (height + width);
}

