#pragma once
#include "Command.h"
#include "Toolbar.h"

class AddOutlineThicknessCommand : public Command {
public:
    AddOutlineThicknessCommand(Toolbar* toolbar);

    void Execute() const override;
 private:
    Toolbar* m_toolbar;

};