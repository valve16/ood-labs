
#include "IShape.h"

class CConvex : public IShape 
{
public:
    CConvex(sf::Vector2f& firstPoint, sf::Vector2f& secondPoint, sf::Vector2f& thirdPoint);
    void Draw(sf::RenderWindow& window) const override;
    sf::ConvexShape ShapeType();
    std::string ToString() const override;
    void Move(const sf::Vector2f& offset) override;

    bool IsPointInside(const sf::Vector2f& point) const override 
    {
        return m_convexShape.getGlobalBounds().contains(point);
    }

    sf::FloatRect getBounds() const override
    {
        return m_convexShape.getGlobalBounds();
    }
    sf::Vector2f GetFirstPoint() const;
    sf::Vector2f GetSecondPoint() const;
    sf::Vector2f GetThirdPoint() const;
private:
    sf::Vector2f m_p1, m_p2, m_p3;
    sf::ConvexShape m_convexShape;
};
