#pragma once
#include "SaveFileStrategy.h"

class CSaveTextFileStrategy : public SaveFileStrategy {
public:
	void Save(std::string filename, std::vector<std::shared_ptr<IShape>> figures) override;
};