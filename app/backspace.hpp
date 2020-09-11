#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"

class backspace : public Command 
{
public:
	backspace();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	char deleted_c;
};

#endif