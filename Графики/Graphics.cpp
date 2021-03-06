
#include "TXLib.h"

void Graphic (double (*func)(double x), COLORREF color);

double Square (double x);
double Cube (double x);
double Giper (double x);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);
    txSetFillColor (TX_WHITE);
    txClear ();

    Graphic (Square,    TX_RED);
    Graphic (Cube,      TX_BLUE);
    Graphic (sin,       TX_GREEN);
    Graphic (cos,       TX_ORANGE);
    Graphic (tan,       TX_BROWN);

    return 0;
    }

//-----------------------------------------------------------------------------

void Graphic (double (*func)(double x), COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);
    double x = -400;
    while (x <= 400)
        {
        double y = func (x);
        txCircle (400 + x*40, -y*40 + 300, 2);
        x += 0.01;
        }
    }

//-----------------------------------------------------------------------------

double Square (double x)
    {
    return x*x/10;
    }

//-----------------------------------------------------------------------------

double Cube (double x)
    {
    return x*x*x/100;
    }

//-----------------------------------------------------------------------------

