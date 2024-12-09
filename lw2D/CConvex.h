#pragma once
#include "IShape.h"

class CConvex : public IShape 
{
public:
    CConvex(sf::Vector2f& firstPoint, sf::Vector2f& secondPoint, sf::Vector2f& thirdPoint);
    void Draw(sf::RenderWindow& window) const override;
    sf::ConvexShape ShapeType();
    std::string ToString() const override;

    bool Contains(const sf::Vector2f& point) const override;
    void Select() override;
    void Deselect() override;
    void DrawSelection(sf::RenderWindow& window) const override;
    void SetFillColor(const sf::Color& color) override;
    void SetOutlineColor(const sf::Color& color) override;
    void SetOutlineThickness(float thickness) override;

    void Move(const sf::Vector2f& offset) override;

    sf::Vector2f GetFirstPoint() const;
    sf::Vector2f GetSecondPoint() const;
    sf::Vector2f GetThirdPoint() const;
private:
    sf::Vector2f m_p1, m_p2, m_p3;
    sf::ConvexShape m_convexShape;
};

