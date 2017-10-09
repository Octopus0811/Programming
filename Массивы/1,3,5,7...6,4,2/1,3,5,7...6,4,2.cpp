
#include "TXLib.h"

void Print (int data[], int size);

int main()
    {
    txCreateWindow (800, 600);

    const int Size = 20;
    int data [Size] = {1};

    int i = 1;

    while (i < Size/2)
        {
        data [i] = data [i - 1] + 2;
        i++;
        }

    while (i > Size/2)
        {
        data [Size - i] = data [i] + 1;
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
