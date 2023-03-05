#include <graphics.h>
#include <time.h>
#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

void drawCloud(int x, int y) {
    for (int i = 0; i < 6; i++) {
        sector(x + i * 10, y, 0, 360, 30, 30);
    }
}

int main() {
    int gd = DETECT, gm;
    int midx, midy;
    time_t rawTime;
    struct tm* currentTime;
    char a[100];

    do {
        rawTime = time(NULL);
        currentTime = localtime(&rawTime);

        initgraph(&gd, &gm, "");

        strftime(a, 100, "%H", currentTime);
        string s = a;
        stringstream obj(s);
        int hour = 0;
        obj >> hour;

        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(COMPLEX_FONT, HORIZ_DIR, 9);
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;

        if (hour >= 6 && hour < 18) {
            setbkcolor(GREEN);
            cleardevice();

            strftime(a, 100, "%H:%M", currentTime);
            moveto(midx, midy);
            outtext(a);

            line(0, getmaxy() * 0.75, getmaxx(), getmaxy() * 0.75);
            setbkcolor(9);
            floodfill(1, 1, 15);

            setbkcolor(YELLOW);
            drawCloud(500, 80);

            for (int h = 0; h <= getmaxx(); h++) {
                for (int v = 0; v <= getmaxy(); v++) {
                    if (getpixel(h, v) == 0) {
                        setbkcolor(9);
                        floodfill(h, v, 15);
                    }
                }
            }
        }
        else {
            setbkcolor(15);
            cleardevice();

            strftime(a, 100, "%H:%M", currentTime);
            moveto(midx, midy);
            outtext(a);

            strftime(a, 100, "%A,%B %dth", currentTime);
            settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
            moveto(midx, midy + 50);
            outtext(a);

            setbkcolor(0);
            drawCloud(500, 80);

            setfillstyle(SOLID_FILL, 15);
            circle(500, 80, 50);
            floodfill(500, 80, 15);

            for (int i = 0; i < 361; i++) {
                putpixel(rand() % getmaxx(), rand() % getmaxy(), 15);
            }
        }

        sleep(60);
    } while (!kbhit());

    closegraph();
    return 0;
}
