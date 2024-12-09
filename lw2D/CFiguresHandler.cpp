#include "CFiguresHandler.h"

const float defaultX = 500;
const float defaultY = 400;

CFiguresHandler::CFiguresHandler(sf::RenderWindow& window)
	:window(window) {}

void CFiguresHandler::CreatingFigures(std::stringstream& ss) {
	std::string figureType;
	ss >> figureType;

	if (figureType == "circle") {

		sf::Vector2f center;
		float radius;
		ss >> center.x >> center.y >> radius;
		auto circle = std::make_unique<CCircle>(center, radius);
		m_figures.push_back(std::make_unique<CCircle>(center, radius));
	}

	if (figureType == "rectangle") {
		std::vector<sf::Vector2f> points;
		points.resize(2);
		ss >> points[0].x >> points[0].y >> points[1].x >> points[1].y;
		m_figures.push_back(std::make_unique<CRectangle>(points[0], points[1]));

	}

	if (figureType == "triangle") {

		sf::Vector2f point1, point2, point3;
		ss >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
		m_figures.push_back(std::make_unique<CConvex>(point1, point2, point3));
	}
}

void CFiguresHandler::Draw() {
	for (auto figure : m_figures) {
		figure->Draw(window);
		figure->DrawSelection(window);
	}
}

void CFiguresHandler::CreateCircleFigure() {
	sf::Vector2f center(defaultX, defaultY);
	float radius = 50;
	//auto circle = std::make_shared<CCircle>(center, radius);
	m_figures.push_back(std::make_unique<CCircle>(center, radius));
}

void CFiguresHandler::CreateRectangleFigure() {

	std::vector<sf::Vector2f> points;
	points.resize(2);
	points[0].x = 50;
	points[0].y = 50;
	points[1].x = 150;
	points[1].y = 150;
	//auto rectangle = std::make_shared<CRectangle>(points[0], points[1]);
	m_figures.push_back(std::make_unique<CRectangle>(points[0], points[1]));
}

void CFiguresHandler::CreateTriangleFigure() {

	sf::Vector2f point1(100, 10), point2, point3;
	point1 = sf::Vector2f(100, 10);
	point2 = sf::Vector2f(50, 110);
	point3 = sf::Vector2f(150, 110);
	//auto triangle = std::make_shared<CConvex>((point1, point2, point3));
	m_figures.push_back(std::make_unique<CConvex>(point1, point2, point3));
}

void CFiguresHandler::CopyFigures(std::vector<std::shared_ptr<IShape>> vecShapes)
{
	m_figures = vecShapes;
}

void CFiguresHandler::SetCursorPosition(const sf::Vector2i& position) 
{
	previousCursorPosition = cursorPosition;
	cursorPosition = position;
}


void CFiguresHandler::SetFillColor(const sf::Color& color) {

	for (const auto& figure : m_figures) {
		if (figure->IsSelected()) {
			figure->SetFillColor(color);
		}
	}
}

void CFiguresHandler::SetOutlineColor(const sf::Color& color) {
	for (const auto& figure : m_figures) {
		if (figure->IsSelected())
		figure->SetOutlineColor(color);
	}
}

void CFiguresHandler::ChangeOutlineThickness(float thickness) {
	if (globalFrame) {
		globalFrame->SetOutlineThickness(thickness);
	}
}

void CFiguresHandler::SetThickness(const float& thickness)
{
	for (const auto& figure : m_figures) {
		if (figure->IsSelected()) {
			figure->SetOutlineThickness(thickness);
		}
	}
}

//void CFiguresHandler::UpdateFrameBound() {
//	if (!m_selectedFigures.empty()) {
//		float left = std::numeric_limits<float>::max();
//		float top = std::numeric_limits<float>::max();
//		float right = std::numeric_limits<float>::lowest();
//		float bottom = std::numeric_limits<float>::lowest();
//
//		for (const auto& figure : m_selectedFigures) {
//			sf::FloatRect bounds = figure->GetGlobalBounds();
//			left = std::min(left, bounds.left);
//			top = std::min(top, bounds.top);
//			right = std::max(right, bounds.left + bounds.width);
//			bottom = std::max(bottom, bounds.top + bounds.height);
//		}
//
//		if (!globalFrame) {
//			globalFrame = std::make_shared<RectangleDecorator>(
//				RectangleShape(Vector2f(0, 0))
//			);
//			globalFrame->SetFillColor(Color::Transparent);
//			globalFrame->SetOutlineColor(Color::Red);
//			globalFrame->SetOutlineThickness(1);
//		}
//
//		globalFrame->SetPosition(left, top);
//		globalFrame->SetSize(right - left, bottom - top);
//	}
//	else if (globalFrame) {
//		globalFrame->SetPosition(0, 0);
//		globalFrame->SetSize(0, 0);
//	}
//}


void CFiguresHandler::SelectFigures() {
	for (const auto& figure : m_figures) {
		sf::Vector2f cursorPositionFloat(cursorPosition);
		if (figure->Contains(cursorPositionFloat)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				figure->Select();
			}
			else
			{
				for (auto& s : m_figures)
				{
					s->Deselect();
				}
				figure->Select();
			}
		}
	}
}

void CFiguresHandler::GroupFigures() {
	auto composite = std::make_shared<CCompositeShape>();
	for (auto& shape : m_figures)
	{
		if (shape->IsSelected())
		{
			composite->AddShape(shape);
		}
	}
	m_figures.erase(std::remove_if(m_figures.begin(), m_figures.end(),
		[](const std::shared_ptr<IShape>& shape) { return shape->IsSelected(); }),
		m_figures.end());
	m_figures.push_back(composite);
}

void CFiguresHandler::UngroupFigures() 
{
	std::vector<std::shared_ptr<IShape>> newShapes;
	for (auto& shape : m_figures) 
	{
		if (auto composite = std::dynamic_pointer_cast<CCompositeShape>(shape)) 
		{
			for (auto& s : composite->GetShapes()) 
			{
				newShapes.push_back(s);
			}
		}
		else 
		{
			newShapes.push_back(shape);
		}
	}
	m_figures = newShapes;
}


void CFiguresHandler::Move() {
	sf::Vector2i dragOffset;

	dragOffset = cursorPosition - previousCursorPosition;
	sf::Vector2f dragOffsetFloat(dragOffset);
	for (auto& shape : m_figures)
	{
		if (shape->IsSelected())
		{
			shape->Move(sf::Vector2f(dragOffsetFloat));
		}
	}
	previousCursorPosition = cursorPosition;
}


//void CFiguresHandler::SelectFigures() {
//	for (size_t i = 0; i < m_figures.size(); i++)
//		if (m_figures[i]->Contains(sf::Vector2f(m_cursorPosition))) {
//			m_figures[i]->Select(); 
//			m_selectedFigures.push_back(m_figures[i]);
//		}
//}

