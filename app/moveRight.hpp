#ifndef MOVERIGHT_HPP
#define MOVERIGHT_HPP

#include "Command.hpp"

class moveRight : public Command 
{
public:
	moveRight();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
};

#endif