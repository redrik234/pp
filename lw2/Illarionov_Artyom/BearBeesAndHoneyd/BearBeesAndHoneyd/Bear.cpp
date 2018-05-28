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
		m_signalToWakeUpBear.wait();
		
		std::printf("-> Bear eats honey \n");

		while (!m_honeyPot.isEmpty())
		{
			m_honeyPot.popPortion();
		}

		std::printf("-> Bear: Eat well! Now I can sleep\n");

		m_signalForBeesToWork.on();
		m_signalToWakeUpBear.off();
	}
}

DWORD WINAPI Bear::actionInThread(LPVOID lParameter)
{
	Bear bear = *(Bear*)lParameter;
	bear.EatHoney();
	return 0;
}