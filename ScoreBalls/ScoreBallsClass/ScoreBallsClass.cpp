
#include "TXLib.h"
#include "ScoreSortClass.h"

#define GAKS(a) GetAsyncKeyState (a)

/*
class BallClass
	{
	public:

	double x_, y_;
	double vx_, vy_;
	int r_;

	BallClass ();

	int id_, score_;
	COLORREF color_;

	void Physics ();
	void DrawBall ();
	};


class Manager
	{
	public:

	BallClass MyBalls_ [1000];
	int BallsNum_;

	Manager ();

	void PhysicsForAllBalls ();
	void DrawAllBalls  ();
	void AddId ();
	void DrawTable ();
	};
*/

void Time     ();

const int WinSizeX = 1000, WinSizeY= 600;
double dt = 0.01;

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (WinSizeX, WinSizeY);
	txDisableAutoPause ();
    txBegin ();
	srand (time(0));

    Manager Manager;

    Manager.AddId ();

	while (!GetAsyncKeyState (VK_ESCAPE))
        {
        Time ();

        Manager.Run ();

        txSetFillColor (RGB(255, 210, 210));
        txSleep (0);
		txClear ();
        }
    return 0;
    }

//-----------------------------------------------------------------------------

void Time ()
	{
	txClearConsole ();
	txSetColor (TX_BLUE);
	txSelectFont ("Comic Sans MS", 25);
	txTextOut (797, 577, "PRESS SPACE TO STOP");

	if (GAKS (VK_SPACE)) dt = 0;
				else if (GetAsyncKeyState ('R') /*&& GAKS ('E') && GAKS ('V') && GAKS ('S')*/)
						{
						dt = -0.01;
						txSetColor (TX_RED);
						txTextOut (202, 577, "*REVERSE*");
						}
					else dt = 0.01;
	}

//-----------------------------------------------------------------------------

BallClass::BallClass ():

	x_ (random(0, WinSizeX)),
    y_ (random(0, WinSizeY)),

    vx_ (random(-300, 300)),
    vy_ (random(-300, 300)),

    r_ (random(30, 40)),

    color_ ((RGB (rand()%200, rand()%220, rand()%220))),

	id_    (0),
    score_ (0)
	{}

//-----------------------------------------------------------------------------

Manager::Manager ():

	MyBalls_  ({}),
	BallsNum_ (15)
	{}

//-----------------------------------------------------------------------------

void Manager::AddId ()
	{
	for (int i = 0; i< BallsNum_; i++)
		{
		MyBalls_[i].id_ = i;
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

void Manager::PhysicsForAllBalls ()
    {
    int i = 0;

    while (i < BallsNum_)
        {
        MyBalls_[i].Physics ();
        i++;
        }
    }

//-----------------------------------------------------------------------------

void BallClass::DrawBall ()
    {
    txSetFillColor  (TX_WHITE);

    txSetColor      (color_, 4);
    txSetFillColor (RGB(255, 235, 235));

    txCircle(x_, y_, r_);

	txSelectFont ("Comic Sans MS", r_);
    char buff [16];
    sprintf (buff, "%2d", id_);
    txTextOut (x_ - (r_/2), y_ - (r_/2), buff);
    //txPixel (Ball.x - (Ball.r/2), Ball.y - (Ball.r/2), 0, 0, 0);
	}

//-----------------------------------------------------------------------------

void Manager::DrawAllBalls ()
    {
    int i = 0;

    while (i < BallsNum_)
        {
        MyBalls_[i].DrawBall ();
        i++;
        }
    }

//-----------------------------------------------------------------------------

void Manager::DrawTable()
	{
	for (int i = 0; i < 10; i++)
		{
		txSetColor (MyBalls_[i].color_, 4);
		txSetFillColor (RGB(255, 255, 255));

		txRectangle (4, 60*i + 2, 200, 60*i + 60 - 3);

		char buff [32];
		sprintf (buff, "id = %3d, score = %3d", MyBalls_[i].id_, MyBalls_[i].score_);
		txSelectFont ("Comic Sans MS", 25);
		txTextOut (15, 60*i + 17, buff);
		}
	}

//-----------------------------------------------------------------------------

void Manager::Run ()
	{
	PhysicsForAllBalls 	();
	DrawAllBalls       	();

	SelectionSort 		();
	DrawTable 			();
	}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
