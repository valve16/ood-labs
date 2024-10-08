
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

    RenderWindow window(VideoMode(400, 400), L"Новый проект", Style::Default);

    window.setVerticalSyncEnabled(true);

    std::vector<std::unique_ptr<IShape>> shapes;
    ShapeOp operations("in.txt", window);
    shapes = operations.ReadShapesFromFileToVector("in.txt");
    operations.RenderShapesFromVector(shapes);
    operations.WriteShapesToFile(shapes, "out.txt");
    return 0;
}