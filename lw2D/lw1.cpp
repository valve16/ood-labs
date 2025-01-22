
#include "IShape.h"
#include "ShapeOp.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(1500, 1000), L"Новый проект", Style::Default);
    window.setVerticalSyncEnabled(true);

    ShapeOp& operations = ShapeOp::GetInstance(window);

    std::vector<std::shared_ptr<IShape>> shapes;
    shapes = operations.ReadShapesFromFileToVector("in.txt");
    operations.RenderShapesFromVector(shapes);

    return 0;
}