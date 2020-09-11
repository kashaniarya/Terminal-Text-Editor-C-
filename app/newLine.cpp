#include "newLine.hpp"

newLine::newLine()
{
	old_x = 0;
	old_l = "";
}

void newLine::execute(EditorModel& model) {
	old_x = model.cursorX;
	old_l = model.body[model.cursorY-1].substr(model.cursorX-1, model.body[model.cursorY-1].size());
	model.newLine();
}

void newLine::undo(EditorModel& model) {
	
	model.body[model.cursorY-1].clear();
	model.cursorY--;		
	model.body[model.cursorY-1].append(old_l);
	model.cursorX = old_x;	
	model.body.erase(model.body.begin()+model.cursorY);
	model.errorMsg = "";
}






















