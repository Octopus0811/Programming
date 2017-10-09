
#include "TXLib.h"

void Print          (int Array [], int Size);
void ROL            (int Array [], int first, int last);
void ROR            (int Array [], int first, int last);
void REV            (int Array [], int Size,  int left, int right);
void AB             (int Array [], int Size,  int leftA, int rightA, int leftB, int rightB);
void Create         (int Array [], int Size);
void BubbleSort     (int Array [], int Size);
void Exchange       (int Array [], int Size,  int a, int b);
int  Min            (int Array [], int Size,  int start);
void SelectionSort  (int Array [], int Size);
int  Sorted         (int Array [], int Size);
void InsertionSort  (int Array [], int Size);
int  Place          (int Array [],            int sorted);
int  BinaryPlace    (int Array [],            int sorted, int x);

void ColorPrint     (int Array [], int Size, int left, int mid, int right);

//-----------------------------------------------------------------------------

int main()
    {
    const int Size = 20;
    int Array [Size] = {};
    Create (Array, Size);
    Print   (Array, Size);
    InsertionSort (Array, Size);
    //printf ("%d ", Sorted (Array, Size));

    Print   (Array, Size);

    return 0;
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

void ROL (int Array [], int first, int last)
    {
    int i = first;
    int temp = Array [first];


    while (i < last)
        {
        Array [i] = Array [i + 1];
        i++;
        }
    Array [last] = temp;
    }

//-----------------------------------------------------------------------------

void ROR (int Array [], int first, int last)
    {
    int i = last;
    int temp = Array [last];

    while (i > first)
        {
        Array [i] = Array [i - 1];
        i--;
        }
    Array [first] = temp;
    }

//-----------------------------------------------------------------------------

void REV (int Array [], int Size, int left, int right)
    {
    for (int i = left; i < (right + left)/2; i++)
        {
        Exchange (Array, Size, i, right - 1 - i);
        }
    }

//-----------------------------------------------------------------------------

void AB (int Array [], int Size, int leftA, int rightA, int leftB, int rightB)
    {
    REV (Array, Size, leftA, rightA);
    REV (Array, Size, leftB, rightB);
    REV (Array, Size, leftA, rightB);
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

void BubbleSort (int Array [], int Size)
    {
    int swaps = 0;
    int comparisons = 0;

    while (true)
        {
        int i = 0;
        int changes = 0;
        int compares = 0;

        while (i < Size - 1)
            {
            if (Array [i]  > Array [i+1])
                {
                Exchange (Array, Size, i, i+1);
                changes ++;
                }
            compares++;
            i++;
            }
        txSleep (0);
        swaps = swaps + changes;
        comparisons = comparisons + compares;
        if (changes == 0) break;
        }
    Print (Array, Size);

    printf ("\n\nПривет, я Cаймон, и я посчитал количество твоих сравнений: %d", comparisons);
    printf ("\nНо ты настолько глупенький :DDD, что сделал вот столько обменов: %d\n", swaps);

    printf ("\nВозьми с полки Нобелевскую премию по аутизму...\n\n\n\n\n");
    }

//-----------------------------------------------------------------------------

int Min (int Array [], int Size, int start)
    {
    int i = start + 1;
    int min = start;

    while (i < Size)
        {
        if (Array [i] < Array [min])
            {
            min = i;
            }
        i++;
        }
    return min;
    }

//-----------------------------------------------------------------------------

void SelectionSort (int Array [], int Size)
    {
    int start = 0;

    while (start < Size)
        {
        Exchange (Array, Size, Min (Array, Size, start), start);
        start++;
        }
    }

//-----------------------------------------------------------------------------

int Sorted (int Array [], int Size)
    {
    int i = 0;
    for (int i = 0; i < Size; i++)
        {
        if (Array [i] > Array [i + 1])
            {
            return i;
            }
        }
    }

//-----------------------------------------------------------------------------

void InsertionSort (int Array [], int Size)
    {
    int sorted = Sorted (Array, Size);
    int number = sorted + 1;

    while (number < Size)
        {
        int start = sorted + 1;
        ROR (Array, BinaryPlace (Array, Sorted (Array, Size), number), start);
        sorted ++;
        if (sorted > 10) break;
        number++;
        }
    }

//-----------------------------------------------------------------------------

int Place (int Array [], int sorted)
    {
    int start = sorted + 1;
    int place = sorted;

    while (true)
        {
        if (place == 0 && Array [start] < Array [0])
            {
            return 0;
            }
        if (Array [start] >= Array[place])
            {
            return place + 1;
            }
            place--;
            sorted ++;
        }
    }

//-----------------------------------------------------------------------------

int BinaryPlace (int Array[], int sorted, int x)
    {
    int left, mid, right;
    left = 0;
    right = sorted - 1;
    while (left <= right)
        {
        mid = (left + right)/2;

        if (Array[x] < Array[mid])
            {
            right = mid - 1;
            }
        else if (Array[x] > Array[mid])
            {
            left = mid + 1;
            }
        else if (Array[x] == Array[mid])
            {
            return mid;
            }

        }

    return left;
    }


//-----------------------------------------------------------------------------

void ColorPrint (int Array [], int Size, int left, int mid, int right)
    {
    for (int i = 0; i < Size; i++)
        {
        if (i < left) $d;
        if (i == left) $r;
        if (i > left) $g;
        if (i == mid) $y;
        if (i > mid) $g;
        if (i == right) $b;
        if (i > right) $d;
        printf ("%d ", Array [i]);
        }
    printf ("\n");
    }
