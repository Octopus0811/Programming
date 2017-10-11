
#include "TXLib.h"
#include "ScoreSortClass.h"

#define GAKS(a) GetAsyncKeyState (a)

void AddId                  (BallClass MyBalls [], int BallsNum);
void PhysicsForAllBalls   	(BallClass MyBalls [], int BallsNum);

void DrawAllBalls           (BallClass MyBalls [], int BallsNum);

void DrawTable				(BallClass MyBalls []);

const int WinSizeX = 1000, WinSizeY= 600;
double dt = 0.01;

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (WinSizeX, WinSizeY);
	txDisableAutoPause ();
    txBegin ();
	srand (time(0));

    const int BallsNum = 15;

    BallClass MyBalls [BallsNum];

    AddId (MyBalls, BallsNum);

	while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetColor (TX_BLUE);
		txSelectFont ("Comic Sans MS", 25);
		txTextOut (797, 577, "PRESS SPACE TO STOP");

        if (GAKS (VK_SPACE)) dt = 0;
			else if (GAKS ('R') && GAKS ('E') && GAKS ('V') && GAKS ('S'))
					{
					dt = -0.01;
					txSetColor (TX_RED);
					txTextOut (202, 577, "*REVERSE*");
					}
				else dt = 0.01;

        PhysicsForAllBalls      (MyBalls, BallsNum);
        DrawAllBalls            (MyBalls, BallsNum);

		SelectionSort (MyBalls, BallsNum);
		DrawTable (MyBalls);

        txSleep (0);
		txClear ();
        }
    return 0;
    }

//-----------------------------------------------------------------------------

BallClass::BallClass ():

	x_(random(0, WinSizeX)),
    y_(random(0, WinSizeY)),

    vx_(random(-300, 300)),
    vy_(random(-300, 300)),

    r_(random(30, 40)),

    color_((RGB (rand()%200, rand()%200, rand()%200))),

    score_(0)
	{}


//-----------------------------------------------------------------------------

void AddId (BallClass MyBalls [], int BallsNum)
	{
	for (int i = 0; i< BallsNum; i++)
		{
		MyBalls[i].id_ = i;
		}
	}

//-----------------------------------------------------------------------------

 void BallClass::Physics ()
    {
    x_ = x_ + vx_ * dt;
    y_ = y_ + vy_ * dt;

    if (x_ + r_ > WinSizeX)
        {
        vx_ = -vx_;
        x_ = WinSizeX - r_;
        score_ ++;
        }
    if (y_ + r_ > WinSizeY)
        {
        vy_ = -vy_;
        y_ = WinSizeY - r_;
        score_ ++;
        }
    if (x_ - r_ < 200)
        {
        vx_ = -vx_;
        x_ = r_ + 200;
        score_ ++;
        }
    if (y_ - r_ < 0)
        {
        vy_ = -vy_;
        y_ = r_;
        score_ ++;
        }
    }

//-----------------------------------------------------------------------------

void PhysicsForAllBalls (BallClass MyBalls [], int BallsNum)
    {
    int i = 0;

    while (i < BallsNum)
        {
        MyBalls[i].Physics ();
        i++;
        }
    }

//-----------------------------------------------------------------------------

void BallClass::DrawBall ()
    {
    txSetFillColor  (TX_WHITE);

    txSetColor      (color_, 4);

    txCircle(x_, y_, r_);

	txSelectFont ("Comic Sans MS", r_);
    char buff [16];
    sprintf (buff, "%2d", id_);
    txTextOut (x_ - (r_/2), y_ - (r_/2), buff);
    //txPixel (Ball.x - (Ball.r/2), Ball.y - (Ball.r/2), 0, 0, 0);
	}

//-----------------------------------------------------------------------------

void DrawAllBalls (BallClass MyBalls[], int BallsNum)
    {
    int i = 0;

    while (i < BallsNum)
        {
        MyBalls[i].DrawBall ();
        i++;
        }
    }

//-----------------------------------------------------------------------------

void DrawTable(BallClass MyBalls [])
	{
	for (int i = 0; i < 10; i++)
		{
		txSetColor (MyBalls[i].color_, 4);
		txRectangle (4, 60*i + 2, 200, 60*i + 60 - 3);

		char buff [32];
		sprintf (buff, "id = %3d, score = %3d", MyBalls[i].id_, MyBalls[i].score_);
		txSelectFont ("Comic Sans MS", 25);
		txTextOut (15, 60*i + 17, buff);
		}
	}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
