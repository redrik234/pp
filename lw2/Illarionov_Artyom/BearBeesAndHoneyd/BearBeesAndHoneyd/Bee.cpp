#include "stdafx.h"
#include "Bee.h"

Bee::Bee(HoneyPot & honeyPot)
	:m_honeyPot(honeyPot)
{
}

void Bee::collectsAndBearsHoney()
{
	if (!m_honeyPot.isFull())
	{
		m_honeyPot.addPortion();
		std::cout << "\n-> Bee collects and bears one portion honey\n" << std::endl;
	}

	if (m_honeyPot.isFull())
	{
		std::cout << "\n-> Pot is full! Call the Kraken!!!" << std::endl;
	}
}
