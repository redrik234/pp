#pragma once

class ThreadHandler
{
public:
	void CreateThrd(LPTHREAD_START_ROUTINE callback, LPVOID lParam);
	void JoinAll();

	~ThreadHandler();
private:
	std::vector<HANDLE> m_threads;
};