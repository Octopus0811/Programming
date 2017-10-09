
#include "TXLib.h"

void PisosPro ();

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);

    txSetFillColor (TX_WHITE);
    txClear ();

    PisosPro ();

    return 0;
    }

//-----------------------------------------------------------------------------
 void PisosPro ()
    {
    for (double x = -400; x <= 400; x += 0.1)
        {
        for (double y = -300; y <= 300; y += 0.1)
            {
            if (x*x + (y-10)*(y-10) < 10 || x >= -5 || y > 1)
                {
                txSetFillColor (TX_BLACK);
                txSetColor (TX_BLACK, 2);
                txCircle (400 + x*10, 300 - y*10, 2);
                }
            }
        }
    }

