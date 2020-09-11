#include "moveUp.hpp"

moveUp::moveUp()
{
	old_x = 0;	
}

void moveUp::execute(EditorModel& model) {
	old_x = model.cursorColumn();
	model.moveUp();
}

void moveUp::undo(EditorModel& model) {
	if(model.cursorY < model.lineCount()) {
		int maxCursorLocation = model.body[model.cursorY].size();
		if (old_x <= maxCursorLocation) {
			model.cursorX = old_x;
			model.cursorY++;
			model.errorMsg = "";
		}
		else {
			model.cursorX = maxCursorLocation+1;
			model.cursorY++;
			model.errorMsg = "";
		}
	}
	else {
		model.errorMsg = "Can't move down.";
	}
}