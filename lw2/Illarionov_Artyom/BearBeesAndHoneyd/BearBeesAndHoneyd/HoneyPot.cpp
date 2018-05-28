#include "stdafx.h"
#include "HoneyPot.h"

HoneyPot::HoneyPot(size_t potSize)
	:m_potSize(potSize)
	,m_portions(0)
{
}

bool HoneyPot::isEmpty() const
{
	return m_portions == 0;
}

bool HoneyPot::isFull() const
{
	return m_portions == m_potSize;
}

void HoneyPot::addPortion()
{
	++m_portions;
}

void HoneyPot::popPortion()
{
	--m_portions;
}
