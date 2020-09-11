#include "moveLeft.hpp"

moveLeft::moveLeft() 
{	
}

void moveLeft::execute(EditorModel& model) {
	model.moveLeft();
}

void moveLeft::undo(EditorModel& model) {
	model.moveRight();
}