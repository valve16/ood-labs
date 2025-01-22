#include "Memento.h"
#include "CConvex.h"
#include "CCircle.h"
#include "CRectangle.h"

Memento::Memento(const std::vector<std::shared_ptr<IShape>>& state)
{
    for (const auto& shape : state) {
        if (dynamic_cast<CCircle*>(shape.get())) {
            auto circle = *dynamic_cast<CCircle*>(shape.get());
            m_state.push_back(std::make_shared<CCircle>(circle));
        }
        else if (dynamic_cast<CRectangle*>(shape.get())) {
            auto rectangle = *dynamic_cast<CRectangle*>(shape.get());
            m_state.push_back(std::make_shared<CRectangle>(rectangle));
        }
        else if (dynamic_cast<CConvex*>(shape.get())) {
            auto rectangle = *dynamic_cast<CConvex*>(shape.get());
            m_state.push_back(std::make_shared<CConvex>(rectangle));
        }
    }
}

std::vector<std::shared_ptr<IShape>> Memento::GetState() const
{
	return m_state;
}