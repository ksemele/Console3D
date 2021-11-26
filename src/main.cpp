#include "vectors.hpp"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <strings.h>

void print_screen(const char *screen, const int &screen_size)
{
    write(0, screen, screen_size);
}

void fill_screen(char *screen, const int & screen_size)
{
    char ch = ' ';
    for (int i = 0; i < screen_size; i++)
        screen[i] = ch;
    screen[screen_size] = '\0';
}

void put_pixel(const vec2 &px, char *screen)
{
    screen[(int)px.x + ((int)px.y / 13)] = '=';
}

int main()
{
    struct winsize win;
    ioctl(0, TIOCGWINSZ, &win);

    int h = win.ws_row;
    int w = win.ws_col;
    int screen_size = h * w;
    char screen[screen_size + 1];
    bzero(screen, screen_size + 1);

    vec2 px = vec2(h/2, w/2);
    std::cout << px.x << " " << px.y; //todo del

    fill_screen(screen, screen_size);
    put_pixel(px, screen);
    // for (;;)
    int frames = 60;
    for (int i = 0; i < frames; i++)
    {
        print_screen(screen, screen_size);
        // sleep(1);
    }

    std::cout << sizeof(screen) << "========== end ==========" << std::endl
              << "lines\tY: " << h << std::endl
              << "columns\tX: " << w << std::endl
              << std::endl;
    return 0;
}
