#include "stdafx.h"
#include "Bear.h"
#include "Bee.h"
#include "HoneyPot.h"

using namespace std;

int main(int argc, char * argv[])
{
	size_t potSize = 20;
	size_t beeCount = 30;

	HANDLE signalToWakeUpBear = CreateEvent(NULL, TRUE, FALSE, NULL);
	HANDLE signalForBeesToWork = CreateEvent(NULL, TRUE, TRUE, NULL);

	HANDLE workingHours = CreateSemaphore(NULL, 1, 1, NULL);

	HoneyPot honeyPot(potSize);

	Bear bear(honeyPot, signalToWakeUpBear, signalForBeesToWork);

	vector<unique_ptr<Bee>> beeSwarm;

	for (size_t i = 0; i < beeCount; ++i)
	{
		beeSwarm.push_back(make_unique<Bee>(i + 1, honeyPot, signalForBeesToWork, signalToWakeUpBear, workingHours));
	}

	vector<HANDLE> threads;
	
	for (auto & bee : beeSwarm)
	{
		threads.push_back(CreateThread(NULL, 0, Bee::actionInThread, bee.get(), 0, NULL));
	}
	threads.push_back(CreateThread(NULL, 0, Bear::actionInThread, &bear, 0, NULL));

	WaitForMultipleObjects(DWORD(threads.size()), threads.data(), TRUE, INFINITE);

	for (auto & thread : threads)
	{
		CloseHandle(thread);
	}
	CloseHandle(signalForBeesToWork);
	CloseHandle(signalToWakeUpBear);
	CloseHandle(workingHours);

	system("pause");
	return 0;
}