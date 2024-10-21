#include "CRectangle.h"

const std::string NAME = "RECTANGLE";

CRectangle::CRectangle(sf::Vector2f& firstPoint, sf::Vector2f& secondPoint)
	: m_p1(firstPoint)
    , m_p2(secondPoint)
{
    // Расчет ширины и высоты
    float width = std::abs(m_p2.x - m_p1.x);
    float height = std::abs(m_p2.y - m_p1.y);

    // Определение верхней левой точки для позиции прямоугольника
    sf::Vector2f position;
    position.x = std::min(m_p1.x, m_p2.x);
    position.y = std::min(m_p1.y, m_p2.y);

    // Установка размеров и позиции прямоугольника
    m_rectangleShape.setSize(sf::Vector2f(width, height));
    m_rectangleShape.setPosition(position);
    m_rectangleShape.setFillColor(sf::Color::Blue);  // Задаем цвет для наглядности
}

void CRectangle::Draw(sf::RenderWindow& window) const
{
	window.draw(m_rectangleShape);
}

sf::RectangleShape CRectangle::ShapeType()
{
    return m_rectangleShape;
}

std::string CRectangle::ToString() const
{
    return NAME;
}

float CRectangle::GetWidth() const
{
    float width = m_rectangleShape.getSize().x;
    return width;
}

float CRectangle::GetHeight() const
{
    float height = m_rectangleShape.getSize().y;
    return height;
}