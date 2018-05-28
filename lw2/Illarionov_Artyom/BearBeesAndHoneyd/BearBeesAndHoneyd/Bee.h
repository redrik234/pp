#pragma once
#include "HoneyPot.h"

class Bee
{
public: 
	Bee(size_t id, HoneyPot & honeyPot, HANDLE signalForBeesToWork
		, HANDLE signalToWakeUpBear, HANDLE workingHours);
	void collectsAndBearsHoney();
	static DWORD WINAPI actionInThread(LPVOID lParameter);
private:
	size_t m_id;
	HoneyPot & m_honeyPot;
	HANDLE m_signalForBeesToWork;
	HANDLE m_signalToWakeUpBear;
	HANDLE m_workingHours;
};