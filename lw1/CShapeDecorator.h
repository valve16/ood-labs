#include "IShape.h"
#include "string"

class CShapeDecorator : public IShape {
protected:
    std::unique_ptr<IShape> m_shape;
public:
    CShapeDecorator(std::unique_ptr<IShape> shape);

    virtual void Draw(sf::RenderWindow& window) const override;

    float GetArea();
    float GetPerimeter();

    virtual ~CShapeDecorator() = default;
};