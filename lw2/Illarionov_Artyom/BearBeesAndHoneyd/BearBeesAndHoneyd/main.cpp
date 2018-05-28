#include "stdafx.h"
#include "Bear.h"
#include "Bee.h"
#include "HoneyPot.h"

int main(int argc, char * argv[])
{
	size_t potSize = 5;
	HoneyPot honeyPot(potSize);

	Bear bear(honeyPot);

	Bee bee(honeyPot);

	while (!honeyPot.isFull())
	{
		bee.collectsAndBearsHoney();
	}

	bear.EatHoney();

	if (honeyPot.isEmpty())
	{
		std::cout << "!!! Honey pot is empty !!!" << std::endl;
	}
	else
	{
		std::cout << "bad" << std::endl;
	}
	system("pause");
	return 0;
}