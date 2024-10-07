#include "ShapeOp.h"
using namespace sf;

ShapeOp::ShapeOp(const std::string& filename, sf::RenderWindow& window)
	: m_window(window)
	, m_filename(filename)
{

}

std::vector<IShape*> ShapeOp::ReadShapesFromFileToVector(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<IShape*> shapes;
    if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
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

        // Чтение типа фигуры
        std::getline(iss, shapeType, ':');
        if (shapeType == "TRIANGLE")
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
            shapes.push_back(new CConvex(points[0], points[1], points[2]));
        }
        else if (shapeType == "RECTANGLE") {
            std::vector<sf::Vector2f> points;
            points.resize(2);
            for (int i = 0; i <= 1; i++)
            {
                size_t pos = line.find("=");
                line = line.substr(pos + 1);
                std::istringstream pointStream(line);
                pointStream >> points[i].x >> ignore >> points[i].y;
            }
            shapes.push_back(new CRectangle(points[0], points[1]));
        }
        else if (shapeType == "CIRCLE") {
            sf::Vector2f center;
            float radius;

            // Чтение C и R
            size_t pos = line.find("=");
            line = line.substr(pos + 1);
            std::istringstream pointStream(line);
            pointStream >> center.x >> ignore >> center.y;

            pos = line.find("=");
            line = line.substr(pos);
            std::istringstream radiusStream(line);
            radiusStream >> ignore >> radius;
            shapes.push_back(new CCircle(center, radius));
        }
    };
    return shapes;
}

void ShapeOp::RenderShapesFromVector(std::vector<IShape*>& shapes)
{
    while (m_window.isOpen())
    {
        Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                m_window.close();
        }

        m_window.clear(); // Очистка окна
        for (const auto& shape : shapes)
        {
            shape->Draw(m_window); // Вызов виртуальной функции Draw для каждой фигуры
        }
        m_window.display();
    }
}
