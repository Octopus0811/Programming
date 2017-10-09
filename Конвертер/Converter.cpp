
#include "TXLib.h"

//-----------------------------------------------------------------------------

struct InitArr
    {
    int array [1024];

    int Length;
    };

//-----------------------------------------------------------------------------

void FromInt        (int Array[], int Num, int System, int* NumSize);
void Exchange       (int Array[], int a, int b);
void Print          (int Array[], int Size);
void REV            (int Array[], int first, int last);
void Inverse        (int Array[], int Size);
void ToInt          (int Array[], int* Num, int System, int NumSize);

//-----------------------------------------------------------------------------

    //{============================================================================
    /*

    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // A,  B,  C,  D,  E,  F ]       SPECIAL:[L, I, P, T, (FOR), ×]
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // 10, 11, 12, 13, 14, 15]               [1, 1, 5, 7, 4,     4]

    1. DED                  {13, 14, 13}
    2. DEAD                 {13, 14, 10, 13}
    3. ACE                  {10, 12, 14}
    4. CAFE                 {12, 10, 15, 14}
    5. BAD                  {11, 10, 13}
    6. 5AFOC                {5, 10, 15, 0, 12}
    7. COFFEE               {12, 0, 15, 15, 14, 14}
    8. 4T                   {4, 7}
    9. BE4                  {11, 14, 4}
    10.LE4T                 {1, 14, 4, 7}
    11.LEFT                 {1, 14, 15, 7}
    12.DEADPOOL             {13, 14, 10, 13, 5, 0, 0, 1}
    13.PLOT                 {5, 1, 0, 7}
    14.PLATE                {5, 1, 10, 7, 14}
    15.TOOL                 {7, 0, 0, 1}
    16.PO4TA                {5, 0, 4, 7, 10}
    17.FEEL                 {15, 14, 14, 1}
    18.POLET                {5, 0, 1, 14, 7}
    19.PECTOLET             {5, 14, 12, 7, 0, 1, 14, 7}
    20.LED                  {1, 14, 13}
    21.LEDOCOL              {1, 14, 13, 12, 0, 1}
    22.DEEP                 {13, 14, 14, 5}
    23.4EL                  {4, 14, 1}
    24.COLT                 {12, 0, 1, 7}
    25.4EP4EL               {4, 14, 5, 4, 14, 1}
    26.PABOTA               {5, 10, 11, 0, 7, 10}
    27.TORT                 {7, 0, 5, 7}
    28.LETO                 {1, 14, 7, 0}
    29.TELO                 {7, 14, 1, 0}
    30.LOAD                 {1, 0, 10, 13}
    31.FEED                 {15, 14, 14, 13}

    */
    //}============================================================================
    /*
    Print(Array, NumSize);

    ToInt(Array, &Num, 16, NumSize);

    printf("%d\n", Num);

    FromInt(Array, Num, 2, &NumSize);

    Print(Array, NumSize);

    Inverse(Array, NumSize);

    Print(Array, NumSize);

    ToInt(Array, &Num, 2, NumSize);

    printf("%d\n", Num);

    FromInt(Array, Num, 16, &NumSize);

    Print(Array, NumSize);
    */
    //}============================================================================

int main()
    {
    int NumSize = 6;

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
        switch(Array[i])                                 //
            {                                            //
            default: printf("%d", Array[i]);             //
                break;                                   //
                                                         //
            case 10: printf("A");                        //
                break;                                   //
                                                         //
            case 11: printf("B");                        //
                break;                                   //
                                                         //
            case 12: printf("C");                        //     FIX ME (IT IS NOT THE BEST VARIANT)
                break;                                   //
                                                         //
            case 13: printf("D");                        //
                break;                                   //
                                                         //
            case 14: printf("E");                        //
                break;                                   //
                                                         //
            case 15: printf("F");                        //
                break;                                   //
            }                                            //
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
        *Num = *Num * System + Array[i];
        i++;
        }
    }

//-----------------------------------------------------------------------------

InitArr Add(InitArr FirstNum, InitArr SecondNum)
    {
    InitArr Result = {};

    int i = 0;
    int mind = 0;

    while (i < First.Length || i < Second.Length)
        {
        Result.Length ++;

        Result.array [i] = First.array [i] + Second.array [i] + mind;
        if (Result.array [i] == 2)
            {
            mind = 1;
            }
        else temp = 0;
        if (Result.array [i] == 3)
            {
            mind = 1
            }
        }
    }

