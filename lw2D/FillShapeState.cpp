#include "FillShapeState.h"
#include "ToolBar.h"
#include "DnDState.h"
#include "FillOutlineState.h"

void FillShapeState::DragAndDrop(Toolbar* toolbar) const
{
    toolbar->SetState(new DragAndDropState());
}
void FillShapeState::FillShape(Toolbar* toolbar) const
{

};
void FillShapeState::FillOutline(Toolbar* toolbar) const
{
    toolbar->SetState(new FillOutlineState());
}