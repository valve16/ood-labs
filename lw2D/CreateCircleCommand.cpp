#include "CreateCircleCommand.h"
#include "Toolbar.h"

CreateCircleCommand::CreateCircleCommand(Toolbar* toolbar)
    : m_toolbar(toolbar) {}

void CreateCircleCommand::Execute() const {
    m_toolbar->CreateCircle();
}