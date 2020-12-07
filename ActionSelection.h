#pragma once
#include "..\CIE202-Electric-Circuit-Sim\Actions\Action.h"

class ActionSelection : public Action
{

private:
	int Cx, Cy;
	public:
		ActionSelection(ApplicationManager* pApp): Action(pApp) { pManager = pApp; }	//constructor
		virtual ~ActionSelection(void);

		//Execute action (code depends on action type)
		virtual void Execute() = 0;

		//To undo this action (code depends on action type)
		virtual void Undo() = 0;

		//To redo this action (code depends on action type)
		virtual void Redo() = 0;
	};

