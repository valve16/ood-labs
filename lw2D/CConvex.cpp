#include "CConvex.h"

const std::string NAME = "CONVEX";

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

std::string CConvex::ToString() const
{
	return NAME;
}

sf::Vector2f CConvex::GetFirstPoint() const
{
	return m_p1;
}

sf::Vector2f CConvex::GetSecondPoint() const
{
	return m_p2;
}

sf::Vector2f CConvex::GetThirdPoint() const
{
	return m_p3;
}

void CConvex::Select() {
	m_isSelected = true;
}

void CConvex::Deselect() {
	m_isSelected = false;
}

bool CConvex::Contains(const sf::Vector2f& point) const {
	return m_convexShape.getGlobalBounds().contains(point);
}

void CConvex::DrawSelection(sf::RenderWindow& window) const {
	if (m_isSelected) {
		sf::RectangleShape rect;
		m_convexShape.getGlobalBounds().getPosition();
		rect.setPosition(m_convexShape.getGlobalBounds().getPosition());
		rect.setSize(m_convexShape.getGlobalBounds().getSize());
		rect.setOutlineColor(sf::Color::Yellow);
		rect.setOutlineThickness(2);
		rect.setFillColor(sf::Color::Transparent);
		window.draw(rect);
	}
}

void CConvex::Move(const sf::Vector2f& offset)
{
	m_convexShape.move(offset);
}