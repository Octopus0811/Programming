
#include "TXLib.h"

void Graphic ();
void Axis ();

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);

    txSetFillColor (TX_WHITE);
    txClear ();

    Axis ();

    Graphic ();

    return 0;
    }

//-----------------------------------------------------------------------------

void Axis ()
    {
    txSetColor (TX_BLACK, 2);
    txLine (400, 0, 400, 600);
    txLine (0, 300, 800, 300);

    int k = 10;
    char str[1024];

    for (int i = -50; i <= 50; i += 1)
        {
            if (i % 5 == 0 && i !=0)
            {
            txCircle (400 + i * k, 300, 3);
            txCircle (400, 300 - i * k, 3);
            sprintf (str, "%d", i);
            txTextOut (390 + i * k, 300, str);
            txTextOut (400, 290 - i * k, str);
            }
        }
    }

//-----------------------------------------------------------------------------

void Graphic ()
    {
    for (double x = -100; x < 100; x += 0.1)
        {
        for (double y = -100; y < 100; y += 0.1)
            {
            if ((x*x + (y - 10)*(y - 10) < 50 && x*x + (y - 10)*(y - 10) > 30 || x*x + (y+10)*(y+10) < 50 && x*x + (y+10)*(y+10) > 30) && x > -1)
                {
                txSetColor (TX_RED, 2);                     //-x/0.5 + y < 20 && -x/0.5 + y > 10 && y < 15
                txSetFillColor (TX_RED);
                txCircle (400 + x*10, 300 - y*10, 1);
                }
            }
        }
    }
// H: x > -15 && x < -10 && y < 15 && y > -15 || x < 15 && x > 10 && y < 15 && y > -15 || x > -10 && x < 10 && y < 3 && y > -3
// K: x > -15 && x < -10 && y < 15 && y > -15 || x + y > -15 && x + y < -9 && x > -15 && y > -15 || -x + y < 15 && -x + y > 9 && x > -15 && y < 15
// 3: (x*x + y*y < 10 && x*x + y*y > 5 || x*x + (y+5)*(y+5) < 10 && x*x + (y+5)*(y+5) > 5) && x > -1









