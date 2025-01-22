#include "SaveTextFileStrategy.h"

void CSaveTextFileStrategy::Save(std::string filename, std::vector<std::shared_ptr<IShape>> figures)
{
	std::ofstream output(filename + ".txt");
	WriteFiguresInfo(output, figures);
	output.close();
}
