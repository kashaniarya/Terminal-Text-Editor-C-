#include "moveRight.hpp"

moveRight::moveRight()
{	
}

void moveRight::execute(EditorModel& model) {
	model.moveRight();
	
}

void moveRight::undo(EditorModel& model) {
	model.moveLeft();
}