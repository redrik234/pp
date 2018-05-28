#pragma once
#include "HoneyPot.h"

class Bear
{
public:
	Bear(HoneyPot & honeyPot);
	void EatHoney();
private:
	HoneyPot & m_honeyPot;
};