#pragma once
#include "SaveFileStrategy.h"

class CSaveBinStrategy : public SaveFileStrategy {
public:
	void Save(std::string filename, std::vector<std::shared_ptr<IShape>> figures) override;
};