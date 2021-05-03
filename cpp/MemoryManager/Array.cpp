#pragma once
#include "Array.hpp"
#include "JackMemory.hpp"

Array Array::create(short size)
{
	return JackMemory::alloc(size);
}
void Array::dispose()
{
	JackMemory::deAlloc(*this);
}

short& Array::operator[](short index)
{
	return JackMemory::memory[index];
}