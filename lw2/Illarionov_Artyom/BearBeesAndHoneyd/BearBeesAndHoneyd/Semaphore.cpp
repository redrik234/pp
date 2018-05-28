#include "stdafx.h"
#include "Semaphore.h"

Semaphore::Semaphore(size_t initCount, size_t maxCount)
{
	m_semaphore = CreateSemaphore(NULL, (LONG)initCount, (LONG)maxCount, NULL);
}

Semaphore::~Semaphore()
{
	CloseHandle(m_semaphore);
}

void Semaphore::wait()
{
	WaitForSingleObject(m_semaphore, INFINITE);
}

void Semaphore::release(size_t releaseCount)
{
	ReleaseSemaphore(m_semaphore, (LONG)releaseCount, NULL);
}
