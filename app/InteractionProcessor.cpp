// InteractionProcessor.cpp
//
// ICS 45C Fall 2018
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();
    std::vector<Command*> undo;
    std::vector<Command*> redo;
    bool undo_again = false;


    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            for(int i=0; i < undo.size(); i++) {
                delete undo.at(i);
            }
            for(int i=0; i < redo.size(); i++) {
                delete redo.at(i);
            }
            break;
        }
        else if (interaction.type() == InteractionType::undo && !undo.empty())
        { 
            if (undo_again == true) {
                for(int i=0; i < redo.size(); i++) {
                    delete redo.at(i);
                }
                undo_again = false;
            }
            undo.back()->undo(model);
            redo.push_back(undo.back());
            undo.pop_back();
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo && !redo.empty())
        {
            redo.back()->execute(model);
            undo.push_back(redo.back());
            redo.pop_back();
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                model.clearErrorMessage();
                undo.push_back(command);
                undo_again = true;
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();
        }
    }
}

