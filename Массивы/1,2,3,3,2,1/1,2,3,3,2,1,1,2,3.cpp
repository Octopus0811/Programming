
#include "TXLib.h"

void Print (int data[], int size);

int main()
    {
    txCreateWindow (800, 600);

    const int Size = 21;
    int data [Size] = {1, 2, 3, 3, 2, 1};

    int i = 6;

    while (i < Size)
        {
        data [i] = data [i - 6];
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
