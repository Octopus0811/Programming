
#include "TXLib.h"

struct Cat
    {
    int x, y;
    int anim;
    };

void PlayCats();
void InitCats    (Cat cats[], int nCats);
void DrawAllCats (Cat cats[], int nCats, HDC image);
void MoveAllCats (Cat cats[], int nCats);

int main()
    {
    txCreateWindow (800, 600);

    PlayCats();

    return 0;
    }

void PlayCats()
    {
    const int nCats = 10;
    Cat cats [nCats] = {};

    InitCats (cats, nCats);

    HDC back     = txLoadImage ("back.bmp");
    HDC catImage = txLoadImage ("cat.bmp");

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), back);

        DrawAllCats (cats, nCats, catImage);
        MoveAllCats (cats, nCats);

        txSleep (100);
        }
    }

void InitCats (Cat cats[], int nCats)
    {
    for (int i = 0; i < nCats; i++)
        {
        cats[i].x = 30 + 70 * i + rand() % 20 - 10;
        cats[i].y = 10 + rand() % 20;
        cats[i].anim = rand() % 5;
        }
    }

void DrawAllCats (Cat cats[], int nCats, HDC image)
    {
    for (int i = 0; i < nCats; i++)
        {
        txTransparentBlt (txDC(), cats[i].x, cats[i].y, 50, 50, image,
                          50 * cats[i].anim, 0, TX_WHITE);

        cats[i].anim = ++cats[i].anim % 5;
        }
    }

void MoveAllCats (Cat cats[], int nCats)
    {
    for (int i = 0; i < nCats; i++)
        {
        cats[i].y += 10 + rand() % 30;
        if (cats[i].y >= txGetExtentY() - 20) cats[i].y = 20;
        }
    }

