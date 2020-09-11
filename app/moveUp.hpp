#ifndef MOVEUP_HPP
#define MOVEUP_HPP

#include "Command.hpp"

class moveUp : public Command 
{
public:
	moveUp();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	int old_x;
};

#endif