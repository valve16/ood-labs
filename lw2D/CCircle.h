
#include "IShape.h"

class CCircle : public IShape 
{
public:
    CCircle(sf::Vector2f& center, float radius);
    void Draw(sf::RenderWindow& window) const override;
    float GetRadius() const;
    std::string ToString() const override;

    bool Contains(const sf::Vector2f& point) const override;
    void Select() override;
    void Deselect() override;
    void DrawSelection(sf::RenderWindow& window) const override;

    void Move(const sf::Vector2f& offset) override;
private:
    sf::Vector2f m_center;
    int m_radius;
    sf::CircleShape m_circleShape;
};

