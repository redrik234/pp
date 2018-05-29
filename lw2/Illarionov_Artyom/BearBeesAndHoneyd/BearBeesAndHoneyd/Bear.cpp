#include "stdafx.h"
#include "Bear.h"

Bear::Bear(HoneyPot & honeyPot, Event & signalToWakeUpBear, Event & signalForBeesToWork)
	:m_honeyPot(honeyPot)
	,m_signalToWakeUpBear(signalToWakeUpBear)
	,m_signalForBeesToWork(signalForBeesToWork)
{
}

void Bear::EatHoney()
{
	while (1)
	{
		m_signalToWakeUpBear.Wait();
		
		std::printf("-> Bear eats honey \n");

		while (!m_honeyPot.IsEmpty())
		{
			m_honeyPot.PopPortion();
		}

		std::printf("-> Bear: Eat well! Now I can sleep\n");

		m_signalForBeesToWork.On();
		m_signalToWakeUpBear.Off();
	}
}

DWORD WINAPI Bear::ActionInThread(LPVOID lParameter)
{
	Bear bear = *(Bear*)lParameter;
	bear.EatHoney();
	return 0;
}