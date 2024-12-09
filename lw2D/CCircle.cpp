#include "CCircle.h"

const std::string NAME = "CIRCLE";

CCircle::CCircle(sf::Vector2f& center, float radius)
	: m_center(center)
	, m_radius(radius)
{
	m_circleShape.setRadius(m_radius);
	m_circleShape.setPosition(m_center);
	m_circleShape.setFillColor(sf::Color::Red);
}

void CCircle::Draw(sf::RenderWindow& window) const
{
	window.draw(m_circleShape);
}

float CCircle::GetRadius() const
{
	return m_radius;
}

std::string CCircle::ToString() const
{
	return NAME;
}

void CCircle::Select() 
{
    m_isSelected = true;
}

void CCircle::Deselect() {
    m_isSelected = false;
}

bool CCircle::Contains(const sf::Vector2f& point) const 
{
    sf::FloatRect bounds = m_circleShape.getGlobalBounds();
    return bounds.contains(point);
}

void CCircle::DrawSelection(sf::RenderWindow& window) const 
{
    if (m_isSelected) 
    {
        sf::RectangleShape rect;
        m_circleShape.getGlobalBounds().getPosition();
        rect.setPosition(m_circleShape.getGlobalBounds().getPosition());
        rect.setSize(m_circleShape.getGlobalBounds().getSize());
        rect.setOutlineColor(sf::Color::Yellow);
        rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color::Transparent);
        window.draw(rect);
    }

}

void CCircle::Move(const sf::Vector2f& offset)
{
    m_center += offset;
    m_circleShape.setPosition(m_center);
}
void CCircle::SetFillColor(const sf::Color& color) {
    m_circleShape.setFillColor(color);
}

void CCircle::SetOutlineColor(const sf::Color& color)  {
    m_circleShape.setOutlineColor(color);
}

void CCircle::SetOutlineThickness(float thickness) {
    m_circleShape.setOutlineThickness(thickness);
}