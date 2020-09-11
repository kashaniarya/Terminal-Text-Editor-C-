#include "backspace.hpp"

#include <iostream>

backspace::backspace()
{
	deleted_c = '\0';
}

void backspace::execute(EditorModel& model) {
	if(model.cursorX != 1){//model.body[model.cursorY-1].size() != 0) {
		deleted_c = model.body[model.cursorY-1].at(model.cursorX-2); 
	}
	model.backspace();
}

void backspace::undo(EditorModel& model) {
	if(deleted_c != '\0') {
		model.insert(deleted_c);
	}
	else {
		model.newLine();
	}
}