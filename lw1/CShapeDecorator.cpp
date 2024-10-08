#include "CShapeDecorator.h"
#include "IShape.h"
#include "CCircle.h"
#include "CConvex.h"
#include "CRectangle.h"
#define _USE_MATH_DEFINES
#include <math.h>

CShapeDecorator::CShapeDecorator(std::unique_ptr<IShape> shape)
	: m_shape(std::move(shape)) 
{
}

void CShapeDecorator::Draw(sf::RenderWindow& window) const 
{
    m_shape->Draw(window);
}

float CShapeDecorator::GetArea()
{
	if (auto circle = dynamic_cast<CCircle*>(m_shape.get()))
	{
		return M_PI * circle->GetRadius() * circle->GetRadius();
	}
	else if (auto rect = dynamic_cast<CRectangle*>(m_shape.get()))
	{
		sf::RectangleShape shape = rect->ShapeType();
		sf::Vector2f size = shape.getSize();
		return size.x * size.y;

	}
	else if (auto conv = dynamic_cast<CConvex*>(m_shape.get()))
	{
		sf::ConvexShape triangle = conv->ShapeType();
		sf::Vector2f point1 = triangle.getPoint(0);
		sf::Vector2f point2 = triangle.getPoint(1);
		sf::Vector2f point3 = triangle.getPoint(2);

		// Вычисление площади по формуле
		float area = 0.5f * std::abs(point1.x * (point2.y - point3.y) +
					 point2.x * (point3.y - point1.y) +
					 point3.x * (point1.y - point2.y));

		return area;
	}
}

float CShapeDecorator::GetPerimeter()
{
    if (auto circle = dynamic_cast<CCircle*>(m_shape.get()))
    {
        // Периметр круга: P = 2 * π * r
        return 2 * M_PI * circle->GetRadius();
    }
    else if (auto rect = dynamic_cast<CRectangle*>(m_shape.get()))
    {
        // Периметр прямоугольника: P = 2 * (width + height)
        sf::RectangleShape shape = rect->ShapeType();
        sf::Vector2f size = shape.getSize();
        return 2 * (size.x + size.y);
    }
    else if (auto conv = dynamic_cast<CConvex*>(m_shape.get()))
    {
        // Периметр треугольника: P = a + b + c
        sf::ConvexShape triangle = conv->ShapeType();
        float perimeter = 0.0f;

        int pointCount = triangle.getPointCount();
        for (int i = 0; i < pointCount; ++i)
        {
            sf::Vector2f point1 = triangle.getPoint(i);
            sf::Vector2f point2 = triangle.getPoint((i + 1) % pointCount); // следующая точка (с циклическим индексом)

            // Длина стороны = расстояние между двумя точками
            float sideLength = std::hypot(point2.x - point1.x, point2.y - point1.y);
            perimeter += sideLength;
        }

        return perimeter;
    }
}