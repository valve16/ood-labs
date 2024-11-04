
#include "IShape.h"

class CRectangle : public IShape 
{
public:
    CRectangle(sf::Vector2f& firstPoint, sf::Vector2f& secondPoint);

    void Draw(sf::RenderWindow& window) const override;

    sf::RectangleShape ShapeType();

    std::string ToString() const override;

    bool Contains(const sf::Vector2f& point) const override;
    void Select() override;
    void Deselect() override;
    void DrawSelection(sf::RenderWindow& window) const override;

    void Move(const sf::Vector2f& offset) override;

    float GetWidth() const;
    float GetHeight() const;

private:
    sf::Vector2f m_p1, m_p2;
    sf::RectangleShape m_rectangleShape;
};

