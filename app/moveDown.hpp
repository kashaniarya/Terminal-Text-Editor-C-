#ifndef MOVEDOWN_HPP
#define MOVEDOWN_HPP

#include "Command.hpp"

class moveDown : public Command 
{
public:
	moveDown();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	int old_x;
};

#endif