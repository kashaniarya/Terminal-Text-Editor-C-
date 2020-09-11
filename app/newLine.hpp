#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"

class newLine : public Command 
{
public:
	newLine();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	int old_x;
	std::string old_l;
};

#endif