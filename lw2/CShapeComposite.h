#pragma once
#include "IShape.h"

class CShapeComposite : public IShape 
{
public:
    void AddShape(std::shared_ptr<IShape> shape) 
    {
        m_shapes.push_back(shape);
    }
    void RemoveShape(std::shared_ptr<IShape> shape) 
    {
        m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
    }

    void Draw(sf::RenderWindow& window) const override 
    {
        for (const auto& shape : m_shapes) 
        {
            shape->Draw(window);
        }
    }

    std::string ToString() const override 
    {
    }

    bool IsPointInside(const sf::Vector2f& point) const override 
    {
        for (const auto& shape : m_shapes) 
        {
            if (shape->IsPointInside(point)) 
            {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::shared_ptr<IShape>> m_shapes;
};