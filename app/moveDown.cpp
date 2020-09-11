#include "moveDown.hpp"

moveDown::moveDown()
{
	old_x = 0;
}

void moveDown::execute(EditorModel& model) {
	old_x = model.cursorColumn();
	model.moveDown();
}

void moveDown::undo(EditorModel& model) {
	//actions to move up
	if(model.cursorY > 1) {
		int maxCursorLocation = model.body[model.cursorY-2].size();
		if (old_x <= maxCursorLocation) {
			model.cursorX = old_x;
			model.cursorY--;
			model.errorMsg = "";
		}
		else {
			model.cursorX = maxCursorLocation+1;
			model.cursorY--;
			model.errorMsg = "";
		}
	}
	else {
		model.errorMsg = "Can't move up.";
	}
}