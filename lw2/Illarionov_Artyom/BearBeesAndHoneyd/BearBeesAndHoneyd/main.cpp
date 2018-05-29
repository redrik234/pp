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
	size_t potSize = 20;
	size_t beeCount = 30;

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