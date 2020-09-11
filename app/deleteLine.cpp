#include "deleteLine.hpp"

deleteLine::deleteLine()
{
	old_x = 0;
	old_l = "";
	old_linecount = 0;
}

void deleteLine::execute(EditorModel& model) {
	old_x = model.cursorX;
	old_l = model.body[model.cursorY-1];
	old_linecount = model.lineCount();
	model.deleteLine();
}

void deleteLine::undo(EditorModel& model) {
	if(model.cursorY == model.lineCount()) {
		model.body.insert(model.body.end(), 1, old_l);
		model.cursorX = old_x;
		model.cursorY++;
	}
	else if(old_linecount != 1) {
		model.body.insert(model.body.begin()+ model.cursorY-1, 1, old_l);
		model.cursorX = old_x;
	}
	else {
		model.body[0].append(old_l);
		model.cursorY = 1;
		model.cursorX = old_x;
	}
}