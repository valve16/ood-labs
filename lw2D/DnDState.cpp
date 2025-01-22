#include "DnDState.h"
#include "FillShapeState.h"
#include "FillOutlineState.h"
#include "ToolBar.h"

void DragAndDropState::DragAndDrop(Toolbar* toolbar) const
{

}
void DragAndDropState::FillShape(Toolbar* toolbar) const
{
    toolbar->SetState(new FillShapeState());
}
void DragAndDropState::FillOutline(Toolbar* toolbar) const
{
    toolbar->SetState(new FillOutlineState());
}