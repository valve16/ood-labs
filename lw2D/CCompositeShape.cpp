#include "CCompositeShape.h"

void CCompositeShape::AddShape(std::shared_ptr<IShape> shape) 
{
    m_shapes.push_back(shape);
}

void CCompositeShape::RemoveShape(std::shared_ptr<IShape> shape) {
    m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
}

void CCompositeShape::Draw(sf::RenderWindow& window) const {
    for (const auto& shape : m_shapes) {
        shape->Draw(window);
    }
}

bool CCompositeShape::Contains(const sf::Vector2f& point) const {
    for (const auto& shape : m_shapes) {
        if (shape->Contains(point)) {
            return true;
        }
    }
    return false;
}

void CCompositeShape::Select() {
    m_isSelected = true;
    for (auto& shape : m_shapes) 
    {
        shape->Select();
        std::cout << shape->ToString() << " " << shape->IsSelected() << "; " << m_isSelected <<"\n";
    }
}

void CCompositeShape::Deselect()
{
    m_isSelected = false;
    for (auto& shape : m_shapes) 
    {
        shape->Deselect();
    }
}

void CCompositeShape::DrawSelection(sf::RenderWindow& window) const {
    if (m_isSelected) {
        for (const auto& shape : m_shapes) {
            shape->DrawSelection(window);
        }
    }
}

void CCompositeShape::Move(const sf::Vector2f& offset) 
{
    for (auto& shape : m_shapes) 
    {
        shape->Move(offset);
        //std::cout << "moved";
    }
}

std::string CCompositeShape::ToString() const {
    return "CompositeShape";
}

std::vector<std::shared_ptr<IShape>> CCompositeShape::GetShapes() const 
{
    return m_shapes;
}