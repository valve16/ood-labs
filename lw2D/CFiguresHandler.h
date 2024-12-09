#pragma once


#include <iostream>
#include <vector>
#include "IShape.h" // selected выбирается
#include "CCircle.h"
#include "CRectangle.h"
#include "CConvex.h"
#include "CCompositeShape.h"
#include <sstream>
#include <stack>
#include <unordered_set>

class CFiguresHandler {
public:
	CFiguresHandler(sf::RenderWindow& window);
	void CreatingFigures(std::stringstream& ss);
	void Draw();
	void CreateCircleFigure();
	void CreateRectangleFigure();
	void CreateTriangleFigure();
	void CopyFigures(std::vector<std::shared_ptr<IShape>> vecShapes);
	void SetCursorPosition(const sf::Vector2i& position);

	void SelectFigures();
	void GroupFigures();
	void UngroupFigures();

	void Move();

	void SetFillColor(const sf::Color& color);

	void SetOutlineColor(const sf::Color& color);

	void ChangeOutlineThickness(float thickness);

	void SetThickness(const float& thickness);

	std::vector<IShape*> GetFigures() const;
private:
	std::vector<std::shared_ptr<IShape>> m_figures;
	//std::unordered_set<std::shared_ptr<IShape>> m_selectedFigures;
	std::shared_ptr<IShape> globalFrame = nullptr;
	sf::RenderWindow& window;
	sf::Vector2i cursorPosition, previousCursorPosition;
	//void UpdateFrameBound();
};