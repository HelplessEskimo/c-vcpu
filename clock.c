#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "clock.h"

void clock(int delay){
    #ifdef _WIN32
    Sleep(delay);
    #else
    usleep(delay*1000);
    #endif
}

int main()
{
    clock(1000);
    return 0;
}
