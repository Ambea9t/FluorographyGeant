
#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
//#include "EventAction.hh"


void ActionInitialization::Build() const
{
	SetUserAction(new PrimaryGenerator);
	SetUserAction(new RunAction);
	//SetUserAction(new EventAction);
}

