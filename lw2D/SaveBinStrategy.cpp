#include "SaveBinStrategy.h"

void CSaveBinStrategy::Save(std::string filename, std::vector<std::shared_ptr<IShape>> figures)
{
    std::ofstream output(filename + ".bin", std::ios::binary);

    std::size_t size = figures.size();
    output.write((char*)&size, sizeof(size));

    for (const auto& figure : figures) {
        output.write((char*)&figure, sizeof(figure));
    }

    output.close();
}
