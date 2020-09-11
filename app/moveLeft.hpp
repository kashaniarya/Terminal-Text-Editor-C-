#ifndef MOVELEFT_HPP
#define MOVELEFT_HPP

#include "Command.hpp"

class moveLeft : public Command 
{
public:
	moveLeft();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
};

#endif