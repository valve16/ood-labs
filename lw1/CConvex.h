
#include "IShape.h"

class CConvex : public IShape {
public:
    CConvex(sf::Vector2f& firstPoint, sf::Vector2f& secondPoint, sf::Vector2f& thirdPoint);
    void Draw(sf::RenderWindow& window) const override;

private:
    sf::Vector2f m_p1, m_p2, m_p3;
    sf::ConvexShape m_convexShape;
};

