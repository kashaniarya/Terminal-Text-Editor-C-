#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP

#include "Command.hpp"

class cursorHome : public Command 
{
public:
	cursorHome();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	int old_x;
};

#endif