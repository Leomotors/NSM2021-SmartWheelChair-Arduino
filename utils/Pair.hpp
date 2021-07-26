#include <stdint.h>

#ifndef MY_PAIR
#define MY_PAIR

struct MyPair
{
public:
    int first;
    int second;
    MyPair(int first, int second) : first(first), second(second) {}
};

#endif
