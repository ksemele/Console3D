#include "vectors.hpp"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

void fill_win(const int & h, const int & w, const char & ch)
{
    char br = '\n';
    for (int i = 0; i < h; i++)
    {
        for (int i = 0; i < w; i++)
        {
            write(0, &ch, 1);
        }
            write(0, &br, 1);
    }
}

int main()
{
    struct winsize win;
    ioctl(0, TIOCGWINSZ, &win);

    int h = win.ws_row;
    int w = win.ws_col;

    char *screen = (char*)malloc(sizeof(char) * h * w +1);


    char ch = '*';
    int frames = 60;
    for (int i = 0; i < frames; i++)
    {
        fill_win(h, w, ch);
    }
    for (int i = 0; i < (h * w); i++)
    {
	    screen[i] = '@';
    }
    screen[h + w] = '\0';

    
    std::cout << screen << "========== end ==========" << std::endl
              << "lines\tY: " << h << std::endl 
              << "columns\tX: " << w << std::endl
              << std::endl;
    return 0;
}
