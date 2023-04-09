#ifndef _LUDO_H_
#define _LUDO_H_


// SOME HEADER FILES
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <winbase.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <locale.h>

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>


// SOME GLOBAL VARIABLES
#define _O_U16TEXT  0x20000
char board[89] = "                                                                                        "; 
struct Position
{
    int Token[4];
    int OnBoard;
    int Passed;
}Red, Blue, Yellow, Green;

// FUNCTION DECLARATIONS
static int set_wide_stream(FILE *stream)
{
    return _setmode(_fileno(stream), _O_U16TEXT);
}

#else


// SOME GLOBAL VARIABLES
#define _O_U16TEXT  0x20000
char board[89] = "                                                                                        "; 
struct Position
{
    int Token[4];
    int OnBoard;
    int Passed;
}Red, Blue, Yellow, Green;

static int set_wide_stream(FILE *stream)
{
    return fwide(stream, 1);
}

#endif

void PRINTBOARD();
void INITIALIZATION();
void PrintTurn(int);
void ModifyBoard();
int AskToken(int, int);
void SmoothClean();
int *ReturnPositions(int);
static int set_wide_stream(FILE *stream);


#endif