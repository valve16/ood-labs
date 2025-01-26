#include "CFiguresHandler.h"
#include "Constants.h"

CFiguresHandler::CFiguresHandler(sf::RenderWindow& window)
	:window(window) {}

void CFiguresHandler::CreatingFigures(std::stringstream& ss) {
	std::string figureType;
	ss >> figureType;

	if (figureType == CIRCLE_TYPE) {

		sf::Vector2f center;
		float radius;
		ss >> center.x >> center.y >> radius;
		auto circle = std::make_unique<CCircle>(center, radius);
		m_figures.push_back(std::make_shared<CCircle>(center, radius));
	}

	if (figureType == RECTANGLE_TYPE) {
		std::vector<sf::Vector2f> points;
		points.resize(NUMBER_POINT_RECT);
		ss >> points[FIRST_POINT].x >> points[FIRST_POINT].y >> points[SECOND_POINT].x >> points[SECOND_POINT].y;
		m_figures.push_back(std::make_shared<CRectangle>(points[FIRST_POINT], points[SECOND_POINT]));

	}

	if (figureType == TRIANGLE_TYPE_H) {

		sf::Vector2f point1, point2, point3;
		ss >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
		m_figures.push_back(std::make_shared<CConvex>(point1, point2, point3));
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
	float radius = DEFAULT_RADIUS;
	//auto circle = std::make_shared<CCircle>(center, radius);
	m_figures.push_back(std::make_shared<CCircle>(center, radius));
}

void CFiguresHandler::CreateRectangleFigure() {

	std::vector<sf::Vector2f> points;
	points.resize(NUMBER_POINT_RECT);
	points[FIRST_POINT].x = DEFAULT_P1_X;
	points[FIRST_POINT].y = DEFAULT_P1_Y;
	points[SECOND_POINT].x = DEFAULT_P2_X;
	points[SECOND_POINT].y = DEFAULT_P2_Y;
	m_figures.push_back(std::make_shared<CRectangle>(points[FIRST_POINT], points[SECOND_POINT]));
}

void CFiguresHandler::CreateTriangleFigure() {

	sf::Vector2f point1(DEFAULT_P1_X_TR, DEFAULT_P1_Y_TR), point2, point3;
	point1 = sf::Vector2f(DEFAULT_P1_X_TR, DEFAULT_P1_Y_TR);
	point2 = sf::Vector2f(DEFAULT_P2_X_TR, DEFAULT_P2_Y_TR);
	point3 = sf::Vector2f(DEFAULT_P3_X_TR, DEFAULT_P3_Y_TR);
	//auto triangle = std::make_shared<CConvex>((point1, point2, point3));
	m_figures.push_back(std::make_shared<CConvex>(point1, point2, point3));
}

void CFiguresHandler::CopyFigures(std::vector<std::shared_ptr<IShape>> vecShapes)
{
	SaveState();
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
		{
			figure->SetOutlineColor(color);
		}
	}
}

void CFiguresHandler::Accept(IVisitor* visitor) {
	for (auto figure : m_figures) 
	{
		//sf::Vector2f cursorPositionFloat(cursorPosition);
		if (figure->IsSelected()) {
			//SaveHistory();
			visitor->VisitFigure(figure);
		}
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

void CFiguresHandler::SaveState()
{
	m_history.push(Memento(m_figures));
}

void CFiguresHandler::Undo()
{
	if (m_history.size() > 1)
	{
		auto previousMemento = m_history.top();
		std::cout << m_history.size();
		m_figures = previousMemento.GetState();
		m_history.pop();
	}
}

std::vector<std::shared_ptr<IShape>> CFiguresHandler::GetFigures() const
{
	return m_figures;
}


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
		else
		{
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
			{
				figure->Deselect();
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

