#pragma once

#include "IVisitor.h"

class FillVisitor : public IVisitor 
{
public:
	FillVisitor(sf::Color color);
	void VisitFigure(std::shared_ptr<IShape> decorator) override;
private:
	sf::Color m_color;
};