#pragma once

class HoneyPot
{
public:
	HoneyPot(size_t potSize);

	bool IsEmpty() const;
	bool IsFull() const;

	void AddPortion();
	void PopPortion();
private:
	size_t m_potSize;
	size_t m_portions;
};