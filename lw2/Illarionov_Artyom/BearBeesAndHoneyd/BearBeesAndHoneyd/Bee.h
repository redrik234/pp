#pragma once
#include "HoneyPot.h"
#include "Event.h"
#include "Semaphore.h"

class Bee
{
public: 
	Bee(size_t id, HoneyPot & honeyPot, Event & signalForBeesToWork
		, Event & signalToWakeUpBear, Semaphore & workingHours);
	void collectsAndBearsHoney();
	static DWORD WINAPI actionInThread(LPVOID lParameter);
private:
	size_t m_id;
	HoneyPot & m_honeyPot;
	Event m_signalForBeesToWork;
	Event m_signalToWakeUpBear;
	Semaphore m_workingHours;
};