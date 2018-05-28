#include "stdafx.h"
#include "Event.h"

Event::Event(bool status)
{
	m_event = CreateEvent(NULL, TRUE, status, NULL);
}

Event::~Event()
{
	CloseHandle(m_event);
}

void Event::on()
{
	SetEvent(m_event);
}

void Event::off()
{
	ResetEvent(m_event);
}

void Event::wait()
{
	WaitForSingleObject(m_event, INFINITE);
}
