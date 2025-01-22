#pragma once
#include "Command.h"
#include "Toolbar.h"

class ReduceThicknessCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    ReduceThicknessCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->ReduceOutlineThickness();
    }
};