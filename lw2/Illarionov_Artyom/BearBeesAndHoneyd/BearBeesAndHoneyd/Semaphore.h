#pragma once

class Semaphore
{
public:
	Semaphore(size_t initCount, size_t maxCount);
	~Semaphore();

	void Wait();
	void Release(size_t releaseCount);
private:
	HANDLE m_semaphore;
};