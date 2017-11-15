
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
   ~BallClass ();

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
	void DrawAllBalls       ();
	void AddId              (int number);
	void AddIdAll           ();
	void DrawTable          ();
	void SelectionSort      ();
	void BallsCounter       ();
	void Run                ();
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

    Manager.AddIdAll ();

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

void BallClass::ConstructNew ()
    {
	x_ = (random(0, WinSizeX));
    y_ = (random(0, WinSizeY));

    vx_ = (random(-300, 300));
    vy_ = (random(-300, 300));

    r_ = (random(30, 40));

    color_ = ((RGB (rand()%200, rand()%220, rand()%220)));

	id_    = (0);
    score_ = (0);
	}

//-----------------------------------------------------------------------------

Manager::Manager ():

	MyBalls_  ({}),
	BallsNum_ (15)
	{}

//-----------------------------------------------------------------------------

BallClass::~BallClass ()
    {
    x_ = 0;
    y_ = 0;

    vx_ = 0;
    vy_ = 0;

    r_ = 0;

    color_ = 0;

	id_   = 0;
    score_ = 0;
    }

//-----------------------------------------------------------------------------

void Manager::AddId (int number)
	{
    MyBalls_[number].id_ = number;
	}

//-----------------------------------------------------------------------------

void Manager::AddIdAll ()
    {
    for (int i = 0; i < BallsNum_; i++)
        {
        AddId (i);
        }
    }

//-----------------------------------------------------------------------------

void BallClass::Physics ()
    {
    x_ = x_ + vx_ * dt;
    y_ = y_ + vy_ * dt;

    if (x_ + r_ > WinSizeX -1 )
        {
        vx_ = -vx_;
        x_ = WinSizeX - r_ - 1;
        score_ ++;
        }
    if (y_ + r_ > WinSizeY - 1)
        {
        vy_ = -vy_;
        y_ = WinSizeY - r_ - 1;
        score_ ++;
        }
    if (x_ - r_ < 201)
        {
        vx_ = -vx_;
        x_ = r_ + 201;
        score_ ++;
        }
    if (y_ - r_ < 1)
        {
        vy_ = -vy_;
        y_ = r_ + 1;
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
	for (int i = 0; i < ((BallsNum_ < 10)? BallsNum_: 10); i++)
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

void Manager::BallsCounter ()
    {
    if (GetAsyncKeyState (VK_UP))
        {
        BallsNum_++;
        AddId (BallsNum_ - 1);
        MyBalls_ [BallsNum_].ConstructNew ();
        }
    if (BallsNum_ > 5 && GetAsyncKeyState (VK_DOWN))
        {
        BallsNum_--;
        MyBalls_ [BallsNum_].~BallClass ();
        MyBalls_ [BallsNum_].score_ = 0;
        }
    }

//-----------------------------------------------------------------------------

void Manager::Run ()
	{
	PhysicsForAllBalls 	();
	DrawAllBalls       	();

	SelectionSort 		();
	DrawTable 			();
	BallsCounter        ();
	}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
