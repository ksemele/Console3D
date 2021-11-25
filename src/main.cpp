#include "vectors.hpp"
#include <iostream>
#include <sys/ioctl.h>

int main()
{
    struct winsize win;
    ioctl(0, TIOCGWINSZ, &win);

    int h = win.ws_row;
    int w = win.ws_col;
    printf ("lines\tY: %d\n", h);
    printf ("columns\tX: %d\n", w);

    std::cout << "========== end ==========" << std::endl;
    return 0;
}