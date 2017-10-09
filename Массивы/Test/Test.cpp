
#include "TXLib.h"

void Test            (int Array [], int Size);
void Print      (int Array [], int Size);
void Create     (int Array [], int Size);
void Exchange   (int Array [], int Size, int a, int b);
void BubbleSort (int Array [], int Size);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);

    const int Size = 16;
    int Array [Size] = {};

    Create          (Array, Size);
    Print           (Array, Size);
    BubbleSort      (Array, Size);
    Print           (Array, Size);
    Test            (Array, Size);

    return 0;
    }

//-----------------------------------------------------------------------------

void Test (int Array [], int Size)
    {
    int failes = 0;
    for (int i = 0; i < Size - 1; i++)
        {
        if (Array [i] > Array [i + 1])
            {
            printf ("\n  %d ошибок", failes);
$r          printf ("\n  %d в ячейке %d не на своeм месте", Array [i], i);
            failes++;
            }
        }
    if (failes == 0)
        {
$g      printf ("\nДопущено 0 ошибок, массив отсортирован");
        }
    }

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
    //srand(time(0));     //эта штука делает полный рандом
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

void BubbleSort (int Array [], int Size)
    {
    while (true)
        {
        int i = 0;
        int changes = 0;


        while (i < Size - 1)
            {
            if (Array [i]  > Array [i+2])
                {
                Exchange (Array, Size, i, i+2);
                changes ++;
                }
            i++;
            }
        if (changes == 0) break;
        }
    }
