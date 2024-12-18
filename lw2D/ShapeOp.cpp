#include "ShapeOp.h"
using namespace sf;
 
const std::string RECT_TYPE = "RECTANGLE";
const std::string TRIANGLE_TYPE = "TRIANGLE";
const std::string CIRC_TYPE = "CIRCLE";
const char EQ_SIGN = '=';

ShapeOp::ShapeOp(const std::string& filename, sf::RenderWindow& window)
	: m_window(window)
	, m_filename(filename)
{

}

std::vector<std::shared_ptr<IShape>> ShapeOp::ReadShapesFromFileToVector(const std::string& filename)
{
    std::ifstream file(filename);
    //std::vector<IShape*> shapes;
    std::vector<std::shared_ptr<IShape>> shapes;

    if (!file.is_open())
    {
        std::cerr << "������ �������� �����: " << filename << std::endl;
        return shapes;
    }

    std::string line;
    while (std::getline(file, line))
    {
        /*std::istringstream iss(line);*/

        char ignore;
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        std::istringstream iss(line);
        std::string shapeType;

        // ������ ���� ������
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

            // ������ C � R
            size_t pos = line.find(EQ_SIGN);
            line = line.substr(pos + 1);
            std::istringstream pointStream(line);
            pointStream >> center.x >> ignore >> center.y;

            pos = line.find(EQ_SIGN);
            line = line.substr(pos);
            std::istringstream radiusStream(line);
            radiusStream >> ignore >> radius;

            // ���������� ������ � ������
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
                    sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    for (auto& shape : shapes) 
                    {
                        if (shape->Contains(mousePos)) 
                        {
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) 
                            {
                                shape->Select();
                                //std::cout << "sel";
                            }
                            else 
                            {
                                for (auto& s : shapes) 
                                {
                                    s->Deselect();
                                }
                                shape->Select();
                                //std::cout << shape->ToString() << " " << shape->IsSelected() << "; ";
                            }
                            isDragging = true;
                            dragStart = mousePos;
                            break;
                        }
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
                    sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    dragOffset = mousePos - dragStart;
                    for (auto& shape : shapes) 
                    {
                        //std::cout << shape->ToString() << " " << shape->IsSelected() << "; ";
                        if (shape->IsSelected()) 
                        {
                            shape->Move(dragOffset);
                            //std::cout << "move";
                        }
                    }
                    dragStart = mousePos;
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    auto composite = std::make_shared<CCompositeShape>();
                    for (auto& shape : shapes) 
                    {
                        if (shape->IsSelected()) 
                        {
                            composite->AddShape(shape);
                        }
                    }

                    shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
                        [](const std::shared_ptr<IShape>& shape) { return shape->IsSelected(); }),
                        shapes.end());

                    shapes.push_back(composite);
                }

                if (event.key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    std::vector<std::shared_ptr<IShape>> newShapes;
                    for (auto& shape : shapes) {
                        if (auto composite = std::dynamic_pointer_cast<CCompositeShape>(shape)) {
                            for (auto& s : composite->GetShapes()) {
                                newShapes.push_back(s);
                            }
                        }
                        else {
                            newShapes.push_back(shape);
                        }
                    }
                    shapes = newShapes;
                }
            }
        }

        m_window.clear();
        for (const auto& shape : shapes) {
            shape->Draw(m_window);
            shape->DrawSelection(m_window);
        }
        m_window.display();
    }
}

void ShapeOp::WriteShapesToFile(std::vector<std::shared_ptr<IShape>>& shapes, const std::string& filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "������ �������� ����� ��� ������: " << filename << std::endl;
        return;
    }

    for (auto& shape : shapes)
    {
        if (shape->ToString() == TRIANGLE_TYPE)
        {
            shape = std::make_shared<CTriangleDecorator>(std::move(shape));
        }
        else if (shape->ToString() == RECT_TYPE)
        {
            shape = std::make_shared<CRectangleDecorator>(std::move(shape));
        }
        else if (shape->ToString() == CIRC_TYPE)
        {
            shape = std::make_shared<CCircleDecorator>(std::move(shape));
        }
    }

    for (auto const& shape : shapes)
    {
        file << shape->ToString() << std::endl;
    }
    file.close(); // ��������� ����
}
