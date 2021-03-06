
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

void Print          (BallType MyBalls [], int BallsNum);
void Create         (BallType MyBalls [], int BallsNum);
void Exchange       (BallType MyBalls [], int BallsNum,  int a, int b);
int  Max            (BallType MyBalls [], int BallsNum,  int start);
void SelectionSort  (BallType MyBalls [], int BallsNum);

//-----------------------------------------------------------------------------

void Print (BallType MyBalls [], int BallsNum)
    {
    printf ("Massive: ");
    for (int i = 0; i < BallsNum; i++)
        {
        printf ("%d ", MyBalls[i].score);
        }
    printf ("\n");
    }

//-----------------------------------------------------------------------------

/*void Create (BallType MyBalls [], int BallsNum)
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

void Exchange (BallType MyBalls [], int BallsNum, int a, int b)
    {
    BallType temp = MyBalls [a];
    MyBalls [a] = MyBalls [b];
    MyBalls [b] = temp;
    }

//-----------------------------------------------------------------------------

int Max (BallType MyBalls [], int BallsNum, int start)
    {
    int i = start + 1;
    int max = start;

    while (i < BallsNum)
        {
        if (MyBalls [i].score > MyBalls [max].score)
            {
            max = i;
            }
        i++;
        }
    return max;
    }

//-----------------------------------------------------------------------------

void SelectionSort (BallType MyBalls [], int BallsNum)
    {
    int start = 0;

    while (start < 10)
        {
        Exchange (MyBalls, BallsNum, Max (MyBalls, BallsNum, start), start);
        start++;
        }
    }

//-----------------------------------------------------------------------------
