// EditorModel.cpp
//
// ICS 45C Fall 2018
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"


EditorModel::EditorModel()
{
	body.push_back("");
	cursorX = 1;
	cursorY = 1;
	errorMsg = "";
}


int EditorModel::cursorLine() const
{
    return cursorY;
}


int EditorModel::cursorColumn() const
{
    return cursorX;
}


int EditorModel::lineCount() const
{
    return body.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return body[lineNumber-1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMsg;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
}


void EditorModel::clearErrorMessage()
{
}

void EditorModel::moveRight()
{
	if(cursorX <= body[EditorModel::cursorLine()-1].size()) {
		cursorX++;
		errorMsg = "";
	}
	else if(EditorModel::cursorLine() < EditorModel::lineCount()) {
		cursorY++;
		cursorX = 1;
		errorMsg = "";
	}
	else {
		errorMsg = "Can't move right.";
	}
}

void EditorModel::moveLeft() {
	if(cursorX > 1) {
		cursorX--;
		errorMsg = "";
	}
	else if(EditorModel::cursorLine() > 1) {
		cursorY--;
		cursorX = body[EditorModel::cursorLine()-1].size()+1;
		errorMsg = "";
	}
	else {
		errorMsg = "Can't move left.";
	}
}


void EditorModel::moveUp() {
	if(cursorY > 1) {
		int maxCursorLocation = body[cursorY-2].size();
		if (cursorX <= maxCursorLocation) {
			cursorY--;
			errorMsg = "";
		}
		else {
			cursorX = maxCursorLocation+1;
			cursorY--;
			errorMsg = "";
		}
	}
	else {
		errorMsg = "Can't move up.";
	}
}

void EditorModel::moveDown() {
	if(cursorY < EditorModel::lineCount()) {
		int maxCursorLocation = body[cursorY].size();
		if (cursorX <= maxCursorLocation) {
			cursorY++;
			errorMsg = "";
		}
		else {
			cursorX = maxCursorLocation+1;
			cursorY++;
			errorMsg = "";
		}
	}
	else {
		errorMsg = "Can't move down.";
	}
}

void EditorModel::cursorHome() {
	cursorX = 1;
	errorMsg = "";
}

void EditorModel::cursorEnd() {
	cursorX = body[cursorY-1].size()+1;
	errorMsg = "";
}


void EditorModel::insert(char c)
{
	std::string before = body[cursorY-1].substr(0,cursorX-1);
	std::string after = body[cursorY-1].substr(cursorX-1, body[cursorY-1].size());
	body[cursorY-1].clear();
	body[cursorY-1].append(before);
	body[cursorY-1] += c;
	body[cursorY-1].append(after);
	cursorX++;
	errorMsg = "";
}

void EditorModel::newLine() {
	std::string before = body[cursorY-1].substr(0,cursorX-1);
	std::string after = body[cursorY-1].substr(cursorX-1, body[cursorY-1].size());
	body[cursorY-1].clear();
	body[cursorY-1].append(before);
	body.insert(body.begin()+cursorY, 1, after);
	cursorY++;
	cursorX = 1;
	errorMsg = "";
}



void EditorModel::backspace() {
	if(cursorX > 1) { 
		std::string before = body[cursorY-1].substr(0,cursorX-2);
		std::string after = body[cursorY-1].substr(cursorX-1, body[cursorY-1].size());
		body[cursorY-1].clear();
		body[cursorY-1].append(before);
		body[cursorY-1].append(after);
		cursorX--;
		errorMsg = "";
	}
	else if (cursorY > 1) {
		int position = body[cursorY-2].size()+1;
		std::string wholeline = body[cursorY-1].substr(0, body[cursorY-1].size());
		body[cursorY-2].append(wholeline);
		cursorY--;
		cursorX = position;
		body[cursorY].clear();
		body.erase(body.begin()+cursorY);
		errorMsg = "";
	}
	else {
		errorMsg = "Nothing to backspace.";
	}
}



void EditorModel::deleteLine() {
	if(cursorY == 1 && body.size() == 1) {
		body[cursorY-1].clear();
		cursorX = 1;
	}
	else if(cursorY == 1 && body.size() != 1) {
		body.erase(body.begin()+cursorY-1);
		if(cursorX > body[cursorY-1].size()+1) {
			cursorX = body[cursorY].size()+1;
		}
	}
	else if(cursorY == body.size()) {
		int pos = body[cursorY-2].size()+1;
		if(cursorX > pos) {
			cursorX = pos;
		}
		body.erase(body.begin()+cursorY-1);
		cursorY--;
	}
	else { //cursorY > 1 but not at bottom of editor lines
		int pos = body[cursorY].size()+1;
		if(cursorX > pos) {
			cursorX = pos;
		}
		body.erase(body.begin()+cursorY-1);
	}
	/*
	if(EditorModel::lineCount() > 1) {
		int max = body[cursorY-2].size()+1;
		//body[cursorY-1].clear();
		body.erase(body.begin()+cursorY-1);
		//cursorY--;
		if(cursorX > max) {
			cursorX = max;
		}
		if(cursorY == body.size() && cursorY != 1) {
			cursorY--;
		}
	}
	else {
		body[cursorY-1].clear();
		cursorX = 1;
	}
	*/
	errorMsg = "";
}


























