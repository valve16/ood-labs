#include "SaveTextFileStrategy.h"
#include "Constants.h"

void CSaveTextFileStrategy::Save(std::string filename, std::vector<std::shared_ptr<IShape>> figures)
{
	std::ofstream output(filename + TXT_FILE);
	WriteFiguresInfo(output, figures);
	output.close();
}
