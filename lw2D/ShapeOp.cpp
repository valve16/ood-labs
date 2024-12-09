#include "ShapeOp.h"
using namespace sf;

const std::string RECT_TYPE = "RECTANGLE";
const std::string TRIANGLE_TYPE = "TRIANGLE";
const std::string CIRC_TYPE = "CIRCLE";
const char EQ_SIGN = '=';

ShapeOp& ShapeOp::GetInstance(sf::RenderWindow& window)
{
    static ShapeOp instance(window);
    return instance;
}

ShapeOp::ShapeOp(sf::RenderWindow& window)
    : m_window(window)
{
    m_figuresHandler = new CFiguresHandler(m_window);
    m_toolbar = new Toolbar(new DragAndDropState(), m_window, m_figuresHandler);
}

ShapeOp::~ShapeOp()
{
}

std::vector<std::shared_ptr<IShape>> ShapeOp::ReadShapesFromFileToVector(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<std::shared_ptr<IShape>> shapes;

    if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return shapes;
    }

    std::string line;
    while (std::getline(file, line))
    {
        char ignore;
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        std::istringstream iss(line);
        std::string shapeType;

        std::getline(iss, shapeType, ':');
        if (shapeType == TRIANGLE_TYPE)
        {
            std::vector<sf::Vector2f> points;
            points.resize(3);
            for (int i = 0; i <= 2; i++)
            {
                size_t pos = line.find("=");
                line = line.substr(pos + 1);
                std::istringstream pointStream(line);
                pointStream >> points[i].x >> ignore >> points[i].y;
            }
            shapes.push_back(std::make_unique<CConvex>(points[0], points[1], points[2]));
        }
        else if (shapeType == RECT_TYPE)
        {
            std::vector<sf::Vector2f> points;
            points.resize(2);
            for (int i = 0; i <= 1; i++)
            {
                size_t pos = line.find(EQ_SIGN);
                line = line.substr(pos + 1);
                std::istringstream pointStream(line);
                pointStream >> points[i].x >> ignore >> points[i].y;
            }
            shapes.push_back(std::make_unique<CRectangle>(points[0], points[1]));
        }
        else if (shapeType == CIRC_TYPE)
        {
            sf::Vector2f center;
            float radius;

            size_t pos = line.find(EQ_SIGN);
            line = line.substr(pos + 1);
            std::istringstream pointStream(line);
            pointStream >> center.x >> ignore >> center.y;

            pos = line.find(EQ_SIGN);
            line = line.substr(pos);
            std::istringstream radiusStream(line);
            radiusStream >> ignore >> radius;

            shapes.push_back(std::make_unique<CCircle>(center, radius));
        }
    };
    return shapes;
}

void ShapeOp::RenderShapesFromVector(std::vector<std::shared_ptr<IShape>>& shapes)
{
    bool isDragging = false;
    sf::Vector2f dragStart;
    sf::Vector2f dragOffset;
    m_figuresHandler->CopyFigures(shapes);
    shapes.clear();
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePosition(event.mouseButton.x, event.mouseButton.y);
                    m_figuresHandler->SetCursorPosition(mousePosition);
                    m_toolbar->SetCursorPosition(mousePosition);
                    m_toolbar->PressToolButton();
                   
                    if (typeid(*m_toolbar->GetState()) == typeid(DragAndDropState))
                    {
                        isDragging = true;
                        m_figuresHandler->SelectFigures();
                    }
                    else 
                    {
                        m_figuresHandler->SelectFigures();
                    }

                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    isDragging = false;
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                if (isDragging)
                {
                    sf::Vector2i mousePosition(event.mouseMove.x, event.mouseMove.y);
                    m_figuresHandler->SetCursorPosition(mousePosition);
                    m_figuresHandler->Move();
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    m_figuresHandler->GroupFigures();
                }

                if (event.key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    m_figuresHandler->UngroupFigures();
                }
            }
        }

        m_window.clear();
        DrawApplication();
        m_window.display();
    }
}



void ShapeOp::DrawApplication() {
    m_figuresHandler->Draw();
    m_toolbar->Draw();
}