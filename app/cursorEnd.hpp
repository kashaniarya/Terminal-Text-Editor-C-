#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"

class cursorEnd : public Command 
{
public:
	cursorEnd();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	int old_x;
};

#endif