#include "CTriangleDecorator.h"
#include "CConvex.h"

CTriangleDecorator::CTriangleDecorator(std::shared_ptr<IShape> shape)
    : CShapeDecorator(std::move(shape))
{
    SetArea();
    SetPerimeter();
};

float CTriangleDecorator::CalculateArea() const
{
    auto triangle = std::dynamic_pointer_cast<CConvex>(m_shape);
    sf::Vector2f p1 = triangle->GetFirstPoint();
    sf::Vector2f p2 = triangle->GetSecondPoint();
    sf::Vector2f p3 = triangle->GetThirdPoint();

    float area = 0.5f * std::abs(p1.x * (p2.y - p3.y) +
        p2.x * (p3.y - p1.y) +
        p3.x * (p1.y - p2.y));

    return area;
}

float CTriangleDecorator::CalculatePerimeter() const
{
    auto triangle = std::dynamic_pointer_cast<CConvex>(m_shape);
    sf::Vector2f p1 = triangle->GetFirstPoint();
    sf::Vector2f p2 = triangle->GetSecondPoint();
    sf::Vector2f p3 = triangle->GetThirdPoint();
    
    float side1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    float side2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
    float side3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));

    return side1 + side2 + side3;
}