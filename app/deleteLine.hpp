#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"

class deleteLine : public Command 
{
public:
	deleteLine();
	virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
	int old_x;
	std::string old_l;
	int old_linecount;
};

#endif