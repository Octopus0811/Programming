
#include "TXLib.h"

struct BallType
    {
    double x, y;
    double vx, vy;
    int r;
    COLORREF color;
    };

void InitBall                  (BallType *Ball, COLORREF color);
void InitAllBalls             (BallType MyBalls [], int BallsNum);
void Physics                   (BallType *Ball, double dt);
void PhysicsForAllBalls   (BallType MyBalls [], int BallsNum, double dt);
void DrawBall                (BallType Ball);
void DrawAllBalls           (BallType MyBalls[], int BallsNum);

const int WinSizeX = 800, WinSizeY= 600;

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (WinSizeX, WinSizeY);
    txBegin ();

    const int BallsNum = 2;

    BallType MyBalls [BallsNum];
    BallType PlayerBall;

    double dt = 0.01;

    InitAllBalls (MyBalls , BallsNum);


    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        PhysicsForAllBalls    (MyBalls , BallsNum, dt);
        DrawAllBalls            (MyBalls , BallsNum);
		txSetFillColor(TX_WHITE);

        txSleep (0);
		txClear ();
        }

    return 0;
    }

//-----------------------------------------------------------------------------

void InitBall (BallType *Ball, COLORREF color)
    {
    Ball->x = random(0, WinSizeX);
    Ball->y = random(0, WinSizeY);

    Ball->vx = random(-200, 200);
    Ball->vy = random(-200, 200);

    Ball->r = random(20, 50);

    Ball->color = (color);
    }

//-----------------------------------------------------------------------------

void InitAllBalls (BallType MyBalls [], int BallsNum)
    {
    int i = 0;

    while (i < BallsNum)
        {
        InitBall (&MyBalls [i], TX_BLUE);
        i++;
        }
    }

//-----------------------------------------------------------------------------

 void Physics (BallType *Ball, double dt)
    {
    Ball->x= Ball->x + Ball->vx * dt;
    Ball->y= Ball->y + Ball->vy * dt;

    if (Ball->x > WinSizeX)
        {
        Ball->vx = -Ball->vx;
        Ball->x = WinSizeX;
        }
    if (Ball->y > WinSizeY)
        {
        Ball->vy = -Ball->vy;
        Ball->y = WinSizeY;
        }
    if (Ball->x < 0)
        {
        Ball->vx = -Ball->vx;
        Ball->x = 0;
        }
    if (Ball->y < 0)
        {
        Ball->vy = -Ball->vy;
        Ball->y = 0;
        }
    }

//-----------------------------------------------------------------------------

void PhysicsForAllBalls (BallType MyBalls [], int BallsNum, double dt)
    {
    int i = 0;

    while (i < BallsNum)
        {
        Physics (&MyBalls [i], dt);
        i++;
        }
    }

//-----------------------------------------------------------------------------

void DrawBall (BallType Ball)
    {
    txSetFillColor (Ball.color);
    txSetColor      (Ball.color);

    txCircle(Ball.x, Ball.y, Ball.r);
    }

//-----------------------------------------------------------------------------

void DrawAllBalls (BallType MyBalls[], int BallsNum)
    {
    int i = 0;

    while (i < BallsNum)
        {
        DrawBall (MyBalls [i]);
        i++;
        }
    }

//-----------------------------------------------------------------------------















