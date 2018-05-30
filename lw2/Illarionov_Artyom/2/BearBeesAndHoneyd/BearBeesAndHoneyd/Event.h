#pragma once

class Event
{
public:
	Event(bool status);
	~Event();

	void On();
	void Off();
	void Wait();
private:
	HANDLE m_event;
};