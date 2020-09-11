#include "cursorHome.hpp"

cursorHome::cursorHome()
{
	old_x = 0;
}

void cursorHome::execute(EditorModel& model) {
	old_x = model.cursorColumn();
	model.cursorHome();
}

void cursorHome::undo(EditorModel& model) {
	model.cursorX = old_x;
}