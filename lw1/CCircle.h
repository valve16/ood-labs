
#include "IShape.h"

class CCircle : public IShape 
{
public:
    CCircle(sf::Vector2f& center, float radius);
    void Draw(sf::RenderWindow& window) const override;

private:
    sf::Vector2f m_center;
    int m_radius;
    sf::CircleShape m_circleShape;
};

