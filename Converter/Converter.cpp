
#include "TXLib.h"

void FromInt        (int Array[], int Num, int System, int* NumSize);
void Exchange       (int Array[], int a, int b);
void Print          (int Array[], int Size);
void REV            (int Array[], int first, int last);
void Inverse        (int Array[], int Size);
void ToInt          (int Array[], int* Num, int System, int NumSize);

//-----------------------------------------------------------------------------

int main()
    {
    int NumSize = 5;
    int Arrayay[1024] = {5, 10, 15, 0, 12};
    int Num = 0;

    Print(Arrayay, NumSize);

    ToInt(Arrayay, &Num, 16, NumSize);

    printf("%d\n", Num);

    FromInt(Arrayay, Num, 2, &NumSize);

    Print(Arrayay, NumSize);

    Inverse(Arrayay, NumSize);

    Print(Arrayay, NumSize);

    ToInt(Arrayay, &Num, 2, NumSize);

    printf("%d\n", Num);

    FromInt(Arrayay, Num, 16, &NumSize);

    Print(Arrayay, NumSize);


    return 0;
    }

//-----------------------------------------------------------------------------

void FromInt(int Array[], int Num, int System, int* NumSize)
    {
    int Size = 0;

    while (Num > 0)
        {
        Array[Size] = Num%System;

        Num = Num/System;

        Size++;

        }
    REV(Array, 0, Size-1);

    *NumSize = Size;
    }

//-----------------------------------------------------------------------------

void Exchange(int Array[], int a, int b)
    {
    int temp = Array[a];
    Array[a] = Array[b];
    Array[b] = temp;
    }

//-----------------------------------------------------------------------------

void REV(int Array[], int first, int last)
    {
    int i = first;

    while(i < ( first + last )/2)
        {
        Exchange(Array, i, last - i);
        i++;
        }


    }

//-----------------------------------------------------------------------------

void Print(int Array[], int Size)
    {
    int i = 0;

    while (i < Size)
        {
        switch(Array[i])
            {
            default: printf("%d", Array[i]);
                break;

            case 10: printf("A");
                break;

            case 11: printf("B");
                break;

            case 12: printf("C");
                break;

            case 13: printf("D");
                break;

            case 14: printf("E");
                break;

            case 15: printf("F");
                break;
            }
        i++;
        }
    printf("\n");

    }

//-----------------------------------------------------------------------------

void Inverse(int Array[], int Size)
    {
    int i = 0;

    while (i < Size)
        {
        if (Array[i] == 0) Array[i] = 1;
            else Array[i] = 0;
        i++;
        }
    }

//-----------------------------------------------------------------------------

void ToInt(int Array[], int* Num, int System, int NumSize)
    {
    *Num = 0;

    int i = 0;

    while (i < NumSize )
        {
        *Num = *Num + Array[i]*pow(System, NumSize - i - 1 );
        i++;
        }

    }
