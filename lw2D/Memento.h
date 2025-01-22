#pragma once
#include "IShape.h"

class Memento
{
public:
	Memento(const std::vector<std::shared_ptr<IShape>>& state);
	std::vector<std::shared_ptr<IShape>> GetState() const;
private:
	std::vector<std::shared_ptr<IShape>> m_state;
};