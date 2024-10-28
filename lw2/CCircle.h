
#include "IShape.h"

class CCircle : public IShape 
{
public:
    CCircle(sf::Vector2f& center, float radius);
    void Draw(sf::RenderWindow& window) const override;
    float GetRadius() const;
    std::string ToString() const override;
    void Move(const sf::Vector2f& offset) override;

    sf::FloatRect getBounds() const override
    {
        return m_circleShape.getGlobalBounds();
    }

    bool IsPointInside(const sf::Vector2f& point) const override 
    {
        float dx = point.x - m_center.x;
        float dy = point.y - m_center.y;
        return (dx * dx + dy * dy) <= m_radius * m_radius;
    }

private:
    sf::Vector2f m_center;
    int m_radius;
    sf::CircleShape m_circleShape;
};

