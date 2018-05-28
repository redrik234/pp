#include "stdafx.h"
#include "Bee.h"

Bee::Bee(size_t id, HoneyPot & honeyPot, Event & signalForBeesToWork
		, Event & signalToWakeUpBear, HANDLE workingHours)
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
		m_signalForBeesToWork.wait();
		WaitForSingleObject(m_workingHours, INFINITE);
		if (!m_honeyPot.isFull())
		{
			m_honeyPot.addPortion();
			std::printf("-> Bee #%zu collects and bears one portion honey\n", m_id);
		}

		if (m_honeyPot.isFull())
		{
			m_signalForBeesToWork.off();
			std::printf("-> Honey pot is full! Call the Kraken!!! #%zu\n", m_id);
			m_signalToWakeUpBear.on();
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
