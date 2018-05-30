#include "stdafx.h"
#include "HoneyPot.h"

HoneyPot::HoneyPot(size_t potSize)
	: m_potSize(potSize)
	, m_portions(0)
{
}

bool HoneyPot::IsEmpty() const
{
	return m_portions == 0;
}

bool HoneyPot::IsFull() const
{
	return m_portions == m_potSize;
}

void HoneyPot::AddPortion()
{
	++m_portions;
}

void HoneyPot::PopPortion()
{
	--m_portions;
}
