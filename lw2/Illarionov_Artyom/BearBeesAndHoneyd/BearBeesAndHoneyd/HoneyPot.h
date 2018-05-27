#pragma once

class HoneyPot
{
public:

	HoneyPot(size_t potSize);

	bool isEmpty() const;
	bool isFull() const;

	void addPortion();
	void popPortion();

private:
	size_t m_potSize;
	size_t m_portions;
};