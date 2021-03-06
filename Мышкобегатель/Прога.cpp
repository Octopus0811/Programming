
#include "TXLib.h"

struct Hero
    {
    POINT pos;
    POINT v;
    double zoom;

    POINT size;
    HDC dc;
    int frame;
    int nFrames;

    int nAnim;
    };

void HeroPlay (Hero hero, HDC back);
void HeroMove (Hero* hero, double dt);
void HeroControl (Hero* hero);
void HeroDraw (Hero* hero);

int main()
    {
    txCreateWindow (800, 600);

    HDC back = txLoadImage ("ROAD.bmp");

    Hero hero = {{100, 100}, {5, 7}, 1, {225, 225}, txLoadImage ("BOY.bmp")};

    HeroPlay (hero, back);

    txDeleteDC (hero.dc);

    txDeleteDC (back);

    return 0;
    }

//-----------------------------------------------------------------------------

void HeroPlay (Hero hero, HDC back)
    {
    POINT size = txGetExtent();
    double dt = 1;

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txBitBlt (txDC(), 0, 0, size.x, size.y, back);

        HeroDraw (&hero);

        HeroControl (&hero);

        HeroMove (&hero, dt);

        txSleep (50);
        }
    }

//-----------------------------------------------------------------------------

void HeroDraw (Hero* hero)
    {
    const COLORREF backColor = RGB (254, 254, 254);

    Win32::TransparentBlt  (txDC(),
                           hero->pos.x - hero->size.x/2,
                           hero->pos.y - hero->size.y/2,
                           hero->size.x * hero->zoom,
                           hero->size.y * hero->zoom,
                           hero->dc,
                           hero->size.x * hero->frame,
                           hero->size.y * hero->nAnim,
                           hero->size.x,
                           hero->size.y,
                           backColor);

    hero->frame = (hero->frame + 1) % 5;

    //txSetColor (TX_LIGHTGREEN);
    //txSetFillColor (TX_LIGHTGREEN);
    //txCircle (hero->pos.x, hero->pos.y, 10);
    }

//-----------------------------------------------------------------------------

void HeroMove (Hero* hero, double dt)
    {
    hero->pos.x += hero->v.x * dt;
    hero->pos.y += hero->v.y * dt;
    }

//-----------------------------------------------------------------------------

void HeroControl (Hero* hero)
    {
    hero->v.x = (txMouseX() - hero->pos.x) / 10;
    hero->v.y = (txMouseY() - hero->pos.y) / 10;

    if (hero->v.x > 0) hero->nAnim = 0;
    else               hero->nAnim = 1;

    if (GetAsyncKeyState (VK_UP)) hero->zoom -= 0.05;
    if (GetAsyncKeyState (VK_DOWN)) hero->zoom += 0.05;
    }

