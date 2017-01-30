#include <termcap.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    struct termios t;
    char buf[8];

    tcgetattr(0, &t);
    t.c_cc[VTIME] = 0;
    t.c_cc[VMIN] = 1;
    t.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &t);

    while (42)
    {
        int sz = read(0, buf, 8);
        for (int i = 0; i < sz; i++)
            printf("%d ", buf[i]);
        printf("\n");
    }
}