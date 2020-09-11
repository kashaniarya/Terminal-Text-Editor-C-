#include "cursorEnd.hpp"

cursorEnd::cursorEnd()
{
	old_x = 0;
}

void cursorEnd::execute(EditorModel& model) {
	old_x = model.cursorColumn();
	model.cursorEnd();
}

void cursorEnd::undo(EditorModel& model) {
	model.cursorX = old_x;
}