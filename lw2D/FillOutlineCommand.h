#pragma once
#include "Command.h"
#include "Toolbar.h"

class FillOutlineCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    FillOutlineCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->FillOutline();
    }
};