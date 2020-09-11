#ifndef ADDCHAR_HPP
#define ADDCHAR_HPP

#include "Command.hpp"

class addChar : public Command 
{
public:
	addChar(char c);
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	char code;
};

#endif