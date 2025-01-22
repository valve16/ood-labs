#include "FillVisitor.h"

FillVisitor::FillVisitor(sf::Color color) :m_color(color) {}

void FillVisitor::VisitFigure(std::shared_ptr<IShape> decorator) {
	decorator->SetFillColor(m_color);
}