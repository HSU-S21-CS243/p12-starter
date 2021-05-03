#pragma once
#include "JackMemory.hpp"

short JackMemory::memory[JackMemory::JACK_MEMORY_SIZE] = { 0 };


short JackMemory::peek(short address)
{
	return 0;
}

void JackMemory::poke(short address, short value)
{

}

/*
TODO: 

Minimum requirement: implement alloc using a linked-list data structure as defined on page 254 in the book
Next level: implement alloc using a binary tree structure for managing data
Full points: implement alloc using a self-balancing tree (AVL or Red-Black) for managing data
*/
Array JackMemory::alloc(short size)
{
	Array result;
	return result;
}

//How to implement dealloc depends on how you implement alloc.
void JackMemory::deAlloc(Array& obj) //recall that a pointer can be used like an array
{

}