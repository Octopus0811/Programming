#include "TXLib.h"

const int BS_NONE      = 0,
          BS_PRESSED   = 1,
          BS_MOUSEOVER = 2;

const int CMD_NONE = 0,
          CMD_GAME = 1,
          CMD_HELP = 2,
          CMD_EXIT = 3;

//-----------------------------------------------------------------------------

struct Button
    {
    int command;

    const char* text;
    const char* helpText;
    COLORREF color;

    HDC dc;

    int x1, y1;
    int x2, y2;

    int status;
    };

//-----------------------------------------------------------------------------

void ButtonsInitAll (Button buttons[], int size, int x0, int y0, int tSizeX, int tSizeY,int buttonSizeX, int ButtonSizeY);

int  RunMenu (Button buttons[], int size);

void ButtonsDrawAll (const Button buttons[], int size);
int  ButtonsTestAll (Button buttons[], int size);

void ButtonDraw (const Button* button);
int  ButtonTest (Button* button);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);
    txSelectFont ("Arial", 30);

    Button b[] = { { CMD_GAME, "������ ���������� �������" ,     "Run the game",  TX_RED },
                   { CMD_HELP, "������ ������",     "Open Help",     TX_RED },
                   { CMD_EXIT, "Exit" ,     "Exit game",     TX_RED }};

    ButtonsInitAll (b, sizearr (b), 200, 150, 50, 100, 300, 80);

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        switch (RunMenu (b, sizearr (b)))
            {
            case CMD_NONE: break;

            case CMD_GAME: system ("start http://petridish.pw/en/");
                           break;

            case CMD_HELP: system ("start http://txlib.ru");
                           break;

            case CMD_EXIT: return 0;

            default:       break;
            }
        }

    return 0;
    }

//-----------------------------------------------------------------------------

int RunMenu (Button menu[], int size)
    {
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear();

        int command = ButtonsTestAll (menu, size);
        if (command != CMD_NONE) return command;

        ButtonsDrawAll (menu, size);

        txSleep (50);
        }

    return CMD_NONE;
    }

void ButtonsInitAll (Button buttons[], int size, int x0, int y0, int tSizeX, int tSizeY,
                     int buttonSizeX, int buttonSizeY)
    {
    for (int i = 0; i < size; i++)
        {
        buttons[i].x1 = x0 + i * tSizeX;
        buttons[i].y1 = y0 + i * tSizeY;
        buttons[i].x2 = x0 + i * tSizeX + buttonSizeX;
        buttons[i].y2 = y0 + i * tSizeY + buttonSizeY;
        }
    }

void ButtonsDrawAll (const Button buttons[], int size)
    {
    for (int i = 0; i < size; i++)
        ButtonDraw (&buttons[i]);
    }

int ButtonsTestAll (Button buttons[], int size)
    {
    for (int i = 0; i < size; i++)
        if (ButtonTest (&buttons[i]) == BS_PRESSED) return buttons[i].command;

    return CMD_NONE;
    }

void ButtonDraw (const Button* button)
    {
    txSetColor (button->color);
    txSetFillColor ((button->status == BS_MOUSEOVER)? TX_LIGHTGREEN : TX_PINK);

    int hint = (button->status == BS_MOUSEOVER)? 5 : 0;

    txRectangle (button->x1 - hint, button->y1 - hint, button->x2 + hint, button->y2 + hint);

    if (button->dc)
        txBitBlt (txDC(), button->x1, button->y1,
                          button->x2 - button->x1, button->y2 - button->y1,
                          button->dc);

    txDrawText (button->x1, button->y1, button->x2, button->y2, button->text);

    if (button->status == BS_MOUSEOVER)
        {
        txSetColor (TX_WHITE);
        txDrawText (0, txGetExtentY() - 30, txGetExtentX(), txGetExtentY(), button->helpText);
        }
    }

int ButtonTest (Button* button)
    {
    int mx = txMouseX(), my = txMouseY();

    if (button->x1 <= mx && mx <= button->x2 &&
        button->y1 <= my && my <= button->y2)
        {
        button->status = BS_MOUSEOVER;

        if (txMouseButtons() == 1)
            {
            button->status = BS_PRESSED;
            return BS_PRESSED;
            }
        }
    else
        button->status = BS_NONE;

    return BS_NONE;
    }




