#include "TXLib.h"


void Print              (int Array [], int Size);
void Create             (int Array [], int Size);
void Exchange           (int Array [], int Size,  int a, int b);
int  Min                (int Array [], int Size,  int start);
void SelectionSort      (int Array [], int Size);
void SelectionGraph     ();
void BubbleSort         (int Array [], int Size);
void BubbleGraph        ();
void ROR                (int Array [], int first, int last);
int  Sorted             (int Array [], int Size);
void BinaryInsertionSort(int Array [], int Size);
void InsertionSort      (int Array [], int Size);
int  Place              (int Array [],            int sorted);
int  BinaryPlace        (int Array [],            int sorted, int x);
void InsertiononGraph         ();
void BinaryInsertiononGraph   ();

int Exchanges;
int Scans;

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

    txClearConsole ();
    }

//-----------------------------------------------------------------------------

void Exchange (int Array [], int Size, int a, int b)
    {
    int d = Array [a];
    Array [a] = Array [b];
    Array [b] = d;
    Exchanges++;
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
        Scans++;
        i++;
        }
    return min;
    }

//-----------------------------------------------------------------------------

void SelectionSort (int Array [], int Size)
    {
    int start = 0;
    Exchanges = 0;
        Scans = 0;

    while (start < Size)
        {
        Exchange (Array, Size, Min (Array, Size, start), start);
        start++;
        }
    }

//-----------------------------------------------------------------------------

void SelectionGraph()
	{
	int Array [777] = {};

	txSetColor (RGB (253,128,1), 2);

	int OLD_X = 0, OLD_Y = 0;


	for (int x = 0; x < 777; x++)
		{
        Create (Array, x);

		SelectionSort (Array, x);

		int y = Exchanges;

        if (y > 700) break;

		txLine (50 + OLD_X, 950 - OLD_Y, 50 + x, 950 - y);

		OLD_X = x;
		OLD_Y = y;

		if (x%50 == 0)
            {
            txSetColor (TX_WHITE);
            txSetFillColor (TX_WHITE);
            txCircle ( 50 + OLD_X, 950 - OLD_Y, 5);
            txSetColor (RGB (253,128,1), 2);
            }
        }

	OLD_X = 0;
	OLD_Y = 0;

	txSetColor (RGB (253,128,1), 2);


	for (int x = 0; x < 256; x++)
        {
        Create (Array, x);
        SelectionSort (Array, x);

		int y = Scans;

        if (y > 700) break;

		txLine (50 + OLD_X, 950 - OLD_Y, 50 + x, 950 - y);

		OLD_X = x;
		OLD_Y = y;
        }
    txClearConsole ();
    //while (txMouseButtons () != 1);
    }

//-----------------------------------------------------------------------------

void BubbleSort (int Array [], int Size)
    {
    Exchanges = 0;
    Scans = 0;

    while (true)
        {
        int i = 0;
        int changes = 0;


        while (i < Size - 1)
            {
            if (Array [i]  > Array [i+1])
                {
                Exchange (Array, Size, i, i+1);
                changes ++;
                }
            Scans++;
            i++;
            }
        if (changes == 0) break;
        }
    }

//-----------------------------------------------------------------------------

void BubbleGraph()
	{
	int Array [256] = {};

	txSetColor (RGB (240,0,1), 2);

	int OLD_X = 0, OLD_Y = 0;


	for (int x = 0; x < 256; x++)
		{
        Create (Array, x);

		BubbleSort (Array, x);

		int y = Exchanges;

        if (y > 700) break;

		txLine (50 + OLD_X, 950 - OLD_Y, 50 + x, 950 - y);

		OLD_X = x;
		OLD_Y = y;

        if (y%50 == 0)
            {
            txSetColor (TX_WHITE);
            txSetFillColor (TX_WHITE);
            txCircle ( 50 + OLD_X, 950 - OLD_Y, 5);
            txSetColor (RGB (240,0,1), 2);
            }
		}

	OLD_X = 0;
	OLD_Y = 0;

	txSetColor (RGB (240,0,1), 2);


	for (int x = 0; x < 256; x++)
        {
        Create (Array, x);

        BubbleSort (Array, x);

		int y = Scans;

		if (y > 700) break;

		txLine (50 + OLD_X, 950 - OLD_Y, 50 + x, 950 - y);

		OLD_X = x;
		OLD_Y = y;
        }
    txClearConsole ();
    //getch ();
    //while (txMouseButtons () != 1);
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
        Exchanges++;
        }
    Array [first] = temp;
    Exchanges++;
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

void BinaryInsertionSort (int Array [], int Size)
    {
    Exchanges = 0;
    Scans     = 0;

    int sorted = Sorted (Array, Size);
    int number = sorted + 1;

    while (number < Size)
        {
        int start = sorted + 1;
        ROR (Array, BinaryPlace (Array, Sorted (Array, Size), number), start);
        sorted ++;
        number++;
        }
    }

//-----------------------------------------------------------------------------

void InsertionSort (int Array [], int Size)
    {
    Exchanges = 0;
    Scans     = 0;

    int sorted = Sorted (Array, Size);
    int number = sorted + 1;

    while (number < Size)
        {
        int start = sorted + 1;
        ROR (Array, Place (Array, Sorted (Array, Size)), start);
        sorted ++;
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
            Scans++;
            return 0;
            }
        if (Array [start] >= Array[place])
            {
            Scans++;
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
            Scans++;
            right = mid - 1;
            }
        else if (Array[x] > Array[mid])
            {
            Scans++;
            left = mid + 1;
            }
        else if (Array[x] == Array[mid])
            {
            Scans++;
            return mid;
            }

        }

    return left;
    }

//-----------------------------------------------------------------------------

void InsertiononGraph()
	{
	int Array [777] = {};

	txSetColor (RGB (255,255,0), 2);

	int OLD_X = 0, OLD_Y = 0;


	for (int x = 0; x < 256; x++)
		{
        Create (Array, x);

		InsertionSort (Array, x);

		int y = Exchanges;

		if (y > 700) break;

		txLine (50 + OLD_X , 950 - OLD_Y, 50 + x, 950 - y);


		OLD_X = x;
		OLD_Y = y;

        //if (y%50 == 0)
           // {
            txSetColor (TX_WHITE);
            txSetFillColor (TX_WHITE);
            txCircle ( 50 + OLD_X, 950 - y + y%50, 4);
            txSetColor (RGB (255,255,0), 2);
          //  }

		}

	OLD_X = 0;
	OLD_Y = 0;

	txSetColor (RGB (255,255,0), 2);


	for (int x = 0; x < 777; x++)
        {
        Create (Array, x);
        InsertionSort (Array, x);

		int y = Scans;

		if (y > 700) break;

		txLine (50 + OLD_X, 950 - OLD_Y, 50 + x, 950 - y);

		OLD_X = x;
		OLD_Y = y;
        }
    txClearConsole ();
    //while (txMouseButtons () != 1);
    }

//-----------------------------------------------------------------------------

void BinaryInsertiononGraph()
	{
	int Array [256] = {};

	txSetColor (RGB (0,176,0), 2);

	int OLD_X = 0, OLD_Y = 0;


	for (int x = 0; x < 256; x++)
		{
        Create (Array, x);

		BinaryInsertionSort (Array, x);

		int y = Exchanges;

        if (y > 700) break;

		txLine (50 + OLD_X, 950 - OLD_Y, 50 + x, 950 - y);

		OLD_X = x;
		OLD_Y = y;

        if (y%50 == 0)
            {
            txSetColor (TX_WHITE);
            txSetFillColor (TX_WHITE);
            txCircle ( 50 + OLD_X, 950 - OLD_Y, 5);
            txSetColor (RGB (0,176,0), 2);
            }

		}

	OLD_X = 0;
	OLD_Y = 0;

	txSetColor (RGB (0,176,0), 2);


	for (int x = 0; x < 256; x++)
        {
        Create (Array, x);
        BinaryInsertionSort (Array, x);

		int y = Scans;

        if (y > 700) break;

		txLine (50 + OLD_X, 950 - OLD_Y, 50 + x, 950 - y);

		OLD_X = x;
		OLD_Y = y;
        }
    txClearConsole ();
    //while (txMouseButtons () != 1);
    }

//-----------------------------------------------------------------------------
