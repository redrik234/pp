#include "stdafx.h"
#include "Bear.h"

Bear::Bear(HoneyPot & honeyPot)
	:m_honeyPot(honeyPot)
{
}

void Bear::EatHoney()
{
	std::cout << "-> Bear eats honey" << std::endl;
	while (!m_honeyPot.isEmpty())
	{
		m_honeyPot.popPortion();
	}

}
