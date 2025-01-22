
#include "IShape.h"
#include "ShapeOp.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "SaveTextFileStrategy.h"
#include "SaveBinStrategy.h"
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(1500, 1000), L"Новый проект", Style::Default);
    window.setVerticalSyncEnabled(true);

    ShapeOp& operations = ShapeOp::GetInstance(window);

    std::vector<std::shared_ptr<IShape>> shapes;
    shapes = operations.ReadShapesFromFileToVector("in.txt");
    operations.RenderShapesFromVector(shapes);

    CSaveTextFileStrategy textSaver;
    std::cout << shapes.size();
    textSaver.Save("output_text", shapes);

    CSaveBinStrategy binSaver;
    binSaver.Save("output_bin", shapes);

    return 0;
}