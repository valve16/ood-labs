#include "Memento.h"
#include "CConvex.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CCompositeShape.h"

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
        else if (auto composite = std::dynamic_pointer_cast<CCompositeShape>(shape)) {
            // ≈сли фигура €вл€етс€ составной, рекурсивно сохран€ем все еЄ внутренние фигуры
            auto compositeCopy = std::make_shared<CCompositeShape>();
            for (const auto& innerShape : composite->GetShapes()) {
                if (dynamic_cast<CCircle*>(innerShape.get())) {
                    auto circle = *dynamic_cast<CCircle*>(innerShape.get());
                    compositeCopy->AddShape(std::make_shared<CCircle>(circle));
                }
                else if (dynamic_cast<CRectangle*>(innerShape.get())) {
                    auto rectangle = *dynamic_cast<CRectangle*>(innerShape.get());
                    compositeCopy->AddShape(std::make_shared<CRectangle>(rectangle));
                }
                else if (dynamic_cast<CConvex*>(innerShape.get())) {
                    auto convex = *dynamic_cast<CConvex*>(innerShape.get());
                    compositeCopy->AddShape(std::make_shared<CConvex>(convex));
                }
                else if (auto innerComposite = std::dynamic_pointer_cast<CCompositeShape>(innerShape)) {
                    // –екурсивно обрабатываем вложенные составные фигуры
                    compositeCopy->AddShape(std::make_shared<CCompositeShape>(*innerComposite));
                }
            }
            m_state.push_back(compositeCopy);
        }
    }
}

std::vector<std::shared_ptr<IShape>> Memento::GetState() const
{
	return m_state;
}