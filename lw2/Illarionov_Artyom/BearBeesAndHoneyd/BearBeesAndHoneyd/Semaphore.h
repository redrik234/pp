#pragma once

class Semaphore
{
public:
	Semaphore(size_t initCount, size_t maxCount);
	~Semaphore();

	void wait();
	void release(size_t releaseCount);
private:
	HANDLE m_semaphore;
};