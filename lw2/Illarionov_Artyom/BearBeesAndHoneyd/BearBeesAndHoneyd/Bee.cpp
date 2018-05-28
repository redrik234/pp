#include "stdafx.h"
#include "Bee.h"

Bee::Bee(size_t id, HoneyPot & honeyPot, HANDLE signalForBeesToWork
		, HANDLE signalToWakeUpBear, HANDLE workingHours)
	:m_id(id)
	,m_honeyPot(honeyPot)
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
			std::printf("-> Bee #%zu collects and bears one portion honey\n", m_id);
		}

		if (m_honeyPot.isFull())
		{
			ResetEvent(m_signalForBeesToWork);
			std::printf("-> Honey pot is full! Call the Kraken!!! #%zu\n", m_id);
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
