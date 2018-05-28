#pragma once
#include "HoneyPot.h"

class Bee
{
public: 
	Bee(HoneyPot & honeyPot, HANDLE signalForBeesToWork
		, HANDLE signalToWakeUpBear, HANDLE workingHours);
	void collectsAndBearsHoney();
	static DWORD WINAPI actionInThread(LPVOID lParameter);
private:
	HoneyPot & m_honeyPot;
	HANDLE m_signalForBeesToWork;
	HANDLE m_signalToWakeUpBear;
	HANDLE m_workingHours;
};