#include "stdafx.h"
#include "ThreadHandler.h"

void ThreadHandler::CreateThrd(LPTHREAD_START_ROUTINE callback, LPVOID lParam)
{
	m_threads.push_back(CreateThread(NULL, 0, callback, lParam, 0, 0));
}

void ThreadHandler::JoinAll()
{
	WaitForMultipleObjects(DWORD(m_threads.size()), m_threads.data(), TRUE, INFINITE);
}

ThreadHandler::~ThreadHandler()
{
	for (auto & thread : m_threads)
	{
		CloseHandle(thread);
	}
}
