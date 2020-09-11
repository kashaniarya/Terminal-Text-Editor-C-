#include "addChar.hpp"

addChar::addChar(char c) {
	code = c;
}

void addChar::execute(EditorModel& model) {
	model.insert(code);
}

void addChar::undo(EditorModel& model) {
	model.backspace();
}