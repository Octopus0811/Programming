
#include "TXLib.h"

struct BallType
    {
    double x, y;
    double vx, vy;
    int r;

    int id;
    int score;

    COLORREF color;
    };

void InitBall               (BallType *Ball, COLORREF color);
void InitAllBalls           (BallType MyBalls [], int BallsNum);
void Physics                (BallType *Ball, double dt);
void PhysicsForAllBalls   	(BallType MyBalls [], int BallsNum, double dt);
void DrawBall               (BallType Ball);
void DrawAllBalls           (BallType MyBalls[], int BallsNum);

void DrawTable				(BallType MyBalls []);

const int WinSizeX = 1000, WinSizeY= 600;

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (WinSizeX, WinSizeY);

    txSetColor (TX_BLUE);
    txSelectFont ("Lucida Console", 40);
    txTextOut (900, 550, "PRESS SPACE TO STOP");

    txDisableAutoPause ();
    txBegin ();

    srand (time(0));

    const int BallsNum = 15;

    BallType MyBalls [BallsNum];
    BallType PlayerBall;

    double dt = 0.01;

    InitAllBalls (MyBalls , BallsNum);


    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        if (GetAsyncKeyState (VK_SPACE)) dt = 0;
			else dt = 0.01;

        PhysicsForAllBalls      (MyBalls, BallsNum, dt);
        DrawAllBalls            (MyBalls, BallsNum);
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

    Ball->vx = random(-300, 300);
    Ball->vy = random(-300, 300);

    Ball->r = random(30, 40);

    Ball->color = (RGB (rand()%200, rand()%200, rand()%200));

    Ball->score = 0;
    }

//-----------------------------------------------------------------------------

void InitAllBalls (BallType MyBalls [], int BallsNum)
    {
    int i = 0;

    while (i < BallsNum)
        {
        InitBall (&MyBalls [i], TX_BLUE);
        MyBalls [i].id = i;
        i++;
        }
    }

//-----------------------------------------------------------------------------

 void Physics (BallType *Ball, double dt)
    {
    Ball->x= Ball->x + Ball->vx * dt;
    Ball->y= Ball->y + Ball->vy * dt;

    if (Ball->x + Ball->r > WinSizeX)
        {
        Ball->vx = -Ball->vx;
        Ball->x = WinSizeX - Ball -> r;
        }
    if (Ball->y + Ball->r > WinSizeY)
        {
        Ball->vy = -Ball->vy;
        Ball->y = WinSizeY - Ball -> r;
        }
    if (Ball->x - Ball->r < 200)
        {
        Ball->vx = -Ball->vx;
        Ball->x = Ball -> r + 200;
        }
    if (Ball->y - Ball->r < 0)
        {
        Ball->vy = -Ball->vy;
        Ball->y = Ball -> r;
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
    txSetFillColor  (TX_WHITE);

    txSetColor      (Ball.color,4);

    txCircle(Ball.x, Ball.y, Ball.r);

	txSelectFont ("Comic Sans MS", Ball.r);
    char buff [16];
    sprintf (buff, "%2d", Ball.id);
    txTextOut (Ball.x - (Ball.r/2), Ball.y - (Ball.r/2), buff);
    //txPixel (Ball.x - (Ball.r/2), Ball.y - (Ball.r/2), 0, 0, 0);
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

void DrawTable(BallType MyBalls [])
	{
	for (int i = 0; i < 10; i++)
		{
		txSetColor (MyBalls[i].color, 3);
		txRectangle (0, 100*i, 200, 100*i+100);
		}
	}
	/*char buff [16];
    sprintf (buff, "id = %3d, score = %3d", Ball.id, Ball.score);  */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
