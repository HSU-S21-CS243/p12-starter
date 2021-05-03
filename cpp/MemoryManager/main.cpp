#include "JackMemory.hpp"
#include <iostream>
using namespace std;

//Jack -> C++ translation of memory test
void runTest()
{
    short temp, err;
    Array a, b, c;
    JackMemory Memory;
    Memory.poke(8000, 333);       // RAM[8000] = 333
    temp = Memory.peek(8000);
    Memory.poke(8001, temp + 1);  // RAM[8001] = 334
    a = Array::create(3);            // uses Memory.alloc
    a[2] = 222;
    Memory.poke(8002, a[2]);      // RAM[8002] = 222
    err = 0;
    b = Array::create(3);
    b[1] = a[2] - 100;
    if (b == a) {					  // Fail compare if b = a
        err = 1;
    }
    Memory.poke(8003, b[1] + err); // RAM[8003] = 122
    err = 0;
    c = Array::create(500);
    c[499] = a[2] - b[1];
    if (c == a) {					  // Fail compare if c = a
        err = 1;
    }
    if (c == b) {					  // Fail compare if c = b
        err = err + 10;
    }
    Memory.poke(8004, c[499] + err); // RAM[8004] = 100

    a.dispose();                   // uses Memory.deAlloc
    b.dispose();

    err = 0;
    b = Array::create(3);
    b[0] = c[499] - 90;
    if (b == c) {					  // Fail compare if b = c
        err = 1;
    }
    Memory.poke(8005, b[0] + err); // RAM[8005] = 10

    c.dispose();
    b.dispose();

    return;
}

void compareResults()
{
    JackMemory memory;
    if (memory.peek(8000) != 333)
    {
        cout << "Memory[8000] != 333" << endl;
    }
    if (memory.peek(8001) != 334)
    {
        cout << "Memory[8000] != 334" << endl;
    }
    if (memory.peek(8002) != 222)
    {
        cout << "Memory[8000] != 222" << endl;
    }
    if (memory.peek(8003) != 122)
    {
        cout << "Memory[8000] != 122" << endl;
    }
    if (memory.peek(8004) != 100)
    {
        cout << "Memory[8000] != 100" << endl;
    }
    if (memory.peek(8005) != 10)
    {
        cout << "Memory[8000] != 10" << endl;
    }
}

int main(void)
{
    runTest();
    compareResults();
    return 0;
}