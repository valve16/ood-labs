#include "CConvex.h"

CConvex::CConvex(sf::Vector2f& firstPoint, sf::Vector2f& secondPoint, sf::Vector2f& thirdPoint)
	: m_p1(firstPoint)
	, m_p2(secondPoint)
	, m_p3(thirdPoint)

{
	// Устанавливаем количество вершин (для треугольника их 3)
	m_convexShape.setPointCount(3);

	// Задаем вершины треугольника
	m_convexShape.setPoint(0, m_p1);
	m_convexShape.setPoint(1, m_p2);
	m_convexShape.setPoint(2, m_p3);

	// Устанавливаем цвет треугольника для наглядности
	m_convexShape.setFillColor(sf::Color::Green);
}

void CConvex::Draw(sf::RenderWindow& window) const
{
	window.draw(m_convexShape);
}

sf::ConvexShape CConvex::ShapeType()
{
	return m_convexShape;
}