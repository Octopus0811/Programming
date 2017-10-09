
#include "TXLib.h"

void Print (int data[], int size);

int main()
    {
    txCreateWindow (800, 600);

    const int Size = 20;
    int data [Size] = {1, 2, 3};

    int i = 3;

    while (i < Size)
        {
        data [i] = data [i - 3];
        i++;
        }

    Print (data, Size);

    return 0;
    }

//-----------------------------------------------------------------------------

void Print (int data[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        printf ("%d ", data [i]);
        }
    }
