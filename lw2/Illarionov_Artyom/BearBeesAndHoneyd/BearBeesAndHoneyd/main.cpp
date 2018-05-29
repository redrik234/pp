#include "stdafx.h"
#include "Bear.h"
#include "Bee.h"
#include "HoneyPot.h"
#include "Event.h"
#include "Semaphore.h"
#include "ThreadHandler.h"

using namespace std;

int main(int argc, char * argv[])
{

	if (argc != 3)
	{
		cout << ">Invalid count of arguments!\n"
			<< "Use: BearBeesAndHoneyd.exe <pot size> <bee count>\n";
		return 1;
	}

	size_t potSize = atoi(argv[1]);
	size_t beeCount = atoi(argv[2]);

	Event signalToWakeUpBear = Event(FALSE);
	Event signalForBeesToWork = Event(TRUE);

	Semaphore workingHours = Semaphore(1, 1);

	HoneyPot honeyPot(potSize);

	Bear bear(honeyPot, signalToWakeUpBear, signalForBeesToWork);

	vector<unique_ptr<Bee>> beeSwarm;

	for (size_t i = 0; i < beeCount; ++i)
	{
		beeSwarm.push_back(make_unique<Bee>(i + 1, honeyPot, signalForBeesToWork, signalToWakeUpBear, workingHours));
	}

	ThreadHandler handler;
	
	for (auto & bee : beeSwarm)
	{
		handler.CreateThrd(Bee::ActionInThread, bee.get());	
	}
	handler.CreateThrd(Bear::ActionInThread, &bear);

	handler.JoinAll();

	return 0;
}