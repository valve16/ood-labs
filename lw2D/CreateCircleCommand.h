#pragma once
#include "Command.h"

class Toolbar;

class CreateCircleCommand : public Command {
public:
    CreateCircleCommand(Toolbar* toolbar);

    void Execute() const override;
private:
    Toolbar* m_toolbar;

};