#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "..\Connections\Connection.h"

//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	string m_Label;
protected:
	//Each component has two ending terminals (term1, term2)

	double term1_volt, term2_volt;	//voltage at terminals 1&2
	double resistance, sourceVoltage; // internal resistance and voltage jump introduced by source

	//Each terminal is connected to set of connections
	Connection *term1_conns[MAX_CONNS]; //list of pointers to connections
	Connection* term2_conns[MAX_CONNS];

	int term1_conn_count=0;	//actual no. of connections to each terminal
	int term2_conn_count=0;

	

public:
	bool Selected;
	GraphicsInfo* m_pGfxInfo;	//The parameters required to draw a component
	
	Component(GraphicsInfo *r_GfxInfo);
	Component();
	bool IsInside(int& x, int& y, UI* pUI);
	void setLabel(string lebel);
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2
	//double getResistance();
	//double getSourceVoltage(TerminalNum Term); // entering from terminal Term. Returns voltage jump/drop for battery, 0 otherwise
	//Connection** getTermConnections(TerminalNum Term);

	//double CalculateTermVoltage(TerminalNum term, double voltAtTerm, double currIntoTerm);	//Calculates the output voltage according to the inputs, sets terminal voltages
	virtual void Operate() = 0; // activates components such as bulb and buzzer

	virtual void Draw(UI*) = 0;	//for each component to Draw itself

	int getCompCenterX(UI*); // get horizontal/vertical centers of the component
	int getCompCenterY(UI*);
	
	//virtual int GetOutStatus()=0;	//returns status of output if BULB/BUZZER, return -1
	//virtual int GetInputStatus()=0;	//returns status of SWITCH, return -1

	//virtual void setInputStatus(STATUS s)=0;	//set status of SWITCH

	void addTerm1Connection(Connection* pConn);
	void addTerm2Connection(Connection* pConn);

	//TerminalNum whichTerminal(Connection* Conn); // returns the terminal to which a connection is connected

	//Destructor must be virtual
	virtual ~Component();
};

#endif
