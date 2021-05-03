#pragma once
#include "Array.hpp"
class JackMemory
{
private:

public:

	//We have 16k worth of 16-bit integers available to us.
	//Of this, memory range 2048-16383 is for heap memory allocation
	static const short JACK_MEMORY_SIZE = 16384;
	static short memory[JACK_MEMORY_SIZE];

	static short peek(short address);
	static void poke(short address, short value);
	static Array alloc(short size);
	static void deAlloc(Array& obj); 
};