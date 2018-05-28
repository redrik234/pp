#pragma once
#include "HoneyPot.h"

class Bear
{
public:
	Bear(HoneyPot & honeyPot, HANDLE signalToWakeUpBear, HANDLE signalForBeesToWork);
	void EatHoney();
	static DWORD WINAPI actionInThread(LPVOID lParameter);
private:
	HoneyPot & m_honeyPot;
	HANDLE m_signalToWakeUpBear;
	HANDLE m_signalForBeesToWork;
};