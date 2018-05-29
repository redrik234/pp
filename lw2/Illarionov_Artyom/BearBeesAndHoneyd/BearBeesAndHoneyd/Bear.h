#pragma once
#include "HoneyPot.h"
#include "Event.h"

class Bear
{
public:
	Bear(HoneyPot & honeyPot, Event & signalToWakeUpBear, Event & signalForBeesToWork);
	void EatHoney();
	static DWORD WINAPI ActionInThread(LPVOID lParameter);
private:
	HoneyPot & m_honeyPot;
	Event m_signalToWakeUpBear;
	Event m_signalForBeesToWork;
};