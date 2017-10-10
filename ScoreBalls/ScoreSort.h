
#include "TXLib.h"

void Print          (int Array [], int Size);
void Create         (int Array [], int Size);
void Exchange       (int Array [], int Size,  int a, int b);
int  Max            (int Array [], int Size,  int start);
void SelectionSort  (int Array [], int Size);

//-----------------------------------------------------------------------------

void Print (int Array [], int Size)
    {
    printf ("Massive: ");
    for (int i = 0; i < Size; i++)
        {
        printf ("%d ", Array[i]);
        }
    printf ("\n");
    }

//-----------------------------------------------------------------------------

void Create (int Array [], int Size)
    {
    srand(time(0));
    int i = 0;

    while (i < Size)
        {
        Array [i] = random(1, 1000);
        i++;
        }
    }

//-----------------------------------------------------------------------------

void Exchange (int Array [], int Size, int a, int b)
    {
    int d = Array [a];
    Array [a] = Array [b];
    Array [b] = d;
    }

//-----------------------------------------------------------------------------

int Max (int Array [], int Size, int start)
    {
    int i = start + 1;
    int max = start;

    while (i < Size)
        {
        if (Array [i] > Array [max])
            {
            max = i;
            }
        i++;
        }
    return max;
    }

//-----------------------------------------------------------------------------

void SelectionSort (int Array [], int Size)
    {
    int start = 0;

    while (start < 10)
        {
        Exchange (Array, Size, Max (Array, Size, start), start);
        start++;
        }
    }

//-----------------------------------------------------------------------------
