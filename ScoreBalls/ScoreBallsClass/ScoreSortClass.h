
#include "TXLib.h"

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

void Print          (BallClass MyBalls [], int BallsNum);
void Create         (BallClass MyBalls [], int BallsNum);
void Exchange       (BallClass MyBalls [], int BallsNum,  int a, int b);
int  Max            (BallClass MyBalls [], int BallsNum,  int start);
void SelectionSort  (BallClass MyBalls [], int BallsNum);

//-----------------------------------------------------------------------------

void Print (BallClass MyBalls [], int BallsNum)
    {
    printf ("Massive: ");
    for (int i = 0; i < BallsNum; i++)
        {
        printf ("%d ", MyBalls[i].score_);
        }
    printf ("\n");
    }

//-----------------------------------------------------------------------------

/*void Create (BallClass MyBalls [], int BallsNum)
    {
    srand(time(0));
    int i = 0;

    while (i < BallsNum)
        {
        MyBalls [i] = random(1, 1000);
        i++;
        }
    } */

//-----------------------------------------------------------------------------

void Exchange (BallClass MyBalls [], int BallsNum, int a, int b)
    {
    BallClass temp = MyBalls [a];
    MyBalls [a] = MyBalls [b];
    MyBalls [b] = temp;
    }

//-----------------------------------------------------------------------------

int Max (BallClass MyBalls [], int BallsNum, int start)
    {
    int i = start + 1;
    int max = start;

    while (i < BallsNum)
        {
        if (MyBalls [i].score_ > MyBalls [max].score_)
            {
            max = i;
            }
        i++;
        }
    return max;
    }

//-----------------------------------------------------------------------------

void SelectionSort (BallClass MyBalls [], int BallsNum)
    {
    int start = 0;

    while (start < 10)
        {
        Exchange (MyBalls, BallsNum, Max (MyBalls, BallsNum, start), start);
        start++;
        }
    }

//-----------------------------------------------------------------------------
