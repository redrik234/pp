#pragma once
#include "HoneyPot.h"

class Bee
{
public: 
	Bee(HoneyPot & honeyPot);
	void collectsAndBearsHoney();
private:
	HoneyPot & m_honeyPot;
};