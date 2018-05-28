#include "stdafx.h"
#include "Bear.h"

Bear::Bear(HoneyPot & honeyPot, HANDLE signalToWakeUpBear, HANDLE signalForBeesToWork)
	:m_honeyPot(honeyPot)
	,m_signalToWakeUpBear(signalToWakeUpBear)
	,m_signalForBeesToWork(signalForBeesToWork)
{
}

void Bear::EatHoney()
{
	while (1)
	{
		WaitForSingleObject(m_signalToWakeUpBear, INFINITE);
		
		std::cout << "\n-> Bear eats honey \n" << std::endl;

		while (!m_honeyPot.isEmpty())
		{
			m_honeyPot.popPortion();
		}

		std::cout << "\n-> Bear: Eat well! Now I can sleep\n" << std::endl;

		SetEvent(m_signalForBeesToWork);
		ResetEvent(m_signalToWakeUpBear);
	}
}

DWORD WINAPI Bear::actionInThread(LPVOID lParameter)
{
	Bear bear = *(Bear*)lParameter;
	bear.EatHoney();
	return 0;
}