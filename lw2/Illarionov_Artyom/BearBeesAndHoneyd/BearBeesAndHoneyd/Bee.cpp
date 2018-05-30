#include "stdafx.h"
#include "Bee.h"
#include <random>

namespace 
{
	const size_t MIN_FLIGHT_TIME = 150;
	const size_t MAX_FLIGHT_TIME = 800;
	const size_t ONE_BEE = 1;
}

Bee::Bee(size_t id, HoneyPot & honeyPot, Event & signalForBeesToWork
		, Event & signalToWakeUpBear, Semaphore & workingHours)
	: m_id(id)
	, m_honeyPot(honeyPot)
	, m_signalForBeesToWork(signalForBeesToWork)
	, m_signalToWakeUpBear(signalToWakeUpBear)
	, m_workingHours(workingHours)
{
}

void Bee::CollectsAndBearsHoney()
{
	std::mt19937 generator{ std::random_device()() };
	std::uniform_int_distribution<int> rand(MIN_FLIGHT_TIME, MAX_FLIGHT_TIME);

	while (1)
	{
		unsigned flightTime = rand(generator);

		Sleep(flightTime);

		m_signalForBeesToWork.Wait();
		m_workingHours.Wait();

		if (!m_honeyPot.IsFull())
		{
			m_honeyPot.AddPortion();
			std::printf("-> Bee #%zu collects and bears one portion honey. Time spent on collecting honey: %u ms\n", m_id, flightTime);
		}

		if (m_honeyPot.IsFull())
		{
			m_signalForBeesToWork.Off();
			std::printf("-> Bee #%zu: - Honey pot is full! Call the Kraken!!!\n", m_id);
			m_signalToWakeUpBear.On();
		}
		m_workingHours.Release(ONE_BEE);
	}
}

DWORD WINAPI Bee::ActionInThread(LPVOID lParameter)
{
	Bee bee = *(Bee*)lParameter;
	bee.CollectsAndBearsHoney();
	return 0;
}
