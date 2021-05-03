#pragma once

class Array
{
private:
    short _memory_pointer = 0;

public:

    Array() {}
    Array(int memory_pointer) : _memory_pointer(memory_pointer) {}

    static Array create(short size);
    void dispose();
    short& operator[](short index);
    bool operator==(Array& other)
    {
        return _memory_pointer == other._memory_pointer;
    }
};