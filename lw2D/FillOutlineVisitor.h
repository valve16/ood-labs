#pragma once

#include "IVisitor.h"

class FillOutlineVisitor : public IVisitor {
public:
	FillOutlineVisitor(sf::Color color);
	void VisitFigure(std::shared_ptr<IShape> decorator) override;
private:
	sf::Color m_color;
};