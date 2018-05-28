#pragma once

class Event
{
public:
	Event(bool status);
	~Event();

	void on();
	void off();
	void wait();
private:
	HANDLE m_event;
};