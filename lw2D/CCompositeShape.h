#pragma once
#include "IShape.h"
#include <vector>

class CCompositeShape : public IShape {
public:
    void AddShape(std::shared_ptr<IShape> shape);
    void RemoveShape(std::shared_ptr<IShape> shape);
    void Draw(sf::RenderWindow& window) const override;
    bool Contains(const sf::Vector2f& point) const override;
    void Select() override;
    void Deselect() override;
    void DrawSelection(sf::RenderWindow& window) const override;
    void Move(const sf::Vector2f& offset);
    void SetFillColor(const sf::Color& color) override;
    void SetOutlineColor(const sf::Color& color) override;
    void SetOutlineThickness(float thickness) override;

    std::string ToString() const override;
    std::vector<std::shared_ptr<IShape>> GetShapes() const;


private:
    std::vector<std::shared_ptr<IShape>> m_shapes;
};