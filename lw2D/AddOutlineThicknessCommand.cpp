#pragma once
#include "AddOutlineThicknessCommand.h"

AddOutlineThicknessCommand::AddOutlineThicknessCommand(Toolbar* toolbar) 
    : m_toolbar(toolbar) {}

void AddOutlineThicknessCommand::Execute() const {
    m_toolbar->AddOutlineThickness();
}