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

void CCircle::Move(const sf::Vector2f& offset)  
{
	m_center += offset;
	m_circleShape.setPosition(m_center);
}