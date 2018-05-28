#include "stdafx.h"
#include "Bee.h"

Bee::Bee(HoneyPot & honeyPot, HANDLE signalForBeesToWork
		, HANDLE signalToWakeUpBear, HANDLE workingHours)
	:m_honeyPot(honeyPot)
	,m_signalForBeesToWork(signalForBeesToWork)
	,m_signalToWakeUpBear(signalToWakeUpBear)
	,m_workingHours(workingHours)
{
}

void Bee::collectsAndBearsHoney()
{
	while (1)
	{
		WaitForSingleObject(m_signalForBeesToWork, INFINITE);
		WaitForSingleObject(m_workingHours, INFINITE);
		if (!m_honeyPot.isFull())
		{
			m_honeyPot.addPortion();
			std::cout << "\n-> Bee collects and bears one portion honey\n" << std::endl;
		}

		if (m_honeyPot.isFull())
		{
			ResetEvent(m_signalForBeesToWork);
			std::cout << "\n-> Honey pot is full! Call the Kraken!!!" << std::endl;
			SetEvent(m_signalToWakeUpBear);
		}
		ReleaseSemaphore(m_workingHours, 1, NULL);
	}
}

DWORD WINAPI Bee::actionInThread(LPVOID lParameter)
{
	Bee bee = *(Bee*)lParameter;
	bee.collectsAndBearsHoney();
	return 0;
}
