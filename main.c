#include "Ludo.h"
int main(void)
{
    // Variables
    int chance = 1;
    int Position, tokn;
    int dice = 0, asked = 0, ColorPassed = 0;
    int *coordinates;
    char Results[5] = "    ";

    system("cls || clear");

    // Initializing
    system("mode con: cols=100 lines=200");
    INITIALIZATION();
    
    while(1)
    {
        setlocale(LC_ALL, "");
        set_wide_stream(stdout);
        // Modifying the board and variable
        loop2:
        asked = 1;
        ModifyBoard();
        PRINTBOARD();
        if(chance == 5)
            chance = 1;

        // Skipping the chances
        if(Red.Passed == 4)
            chance = 2;
        if(Blue.Passed == 4)
            chance = 3;
        if(Yellow.Passed == 4)
            chance = 4;
        if(Green.Passed == 4)
            chance = 1;
        
        // Asking to roll the dice
        SmoothClean();
        PrintTurn(chance);
        wprintf(L"\nPress any key to roll the dice...");
        getch();
        wprintf(L"\nRolling the dice...\n");

        // Rolling the dice
        srand(time(NULL));
        SmoothClean();
        PrintTurn(chance);
        wprintf(L"\n\n%d",dice = (rand() % (6-1+1) + 1));
        Sleep(1000);

        // Printing the dice result
        SmoothClean();
        PrintTurn(chance);
        wprintf(L"\n\nThe dice rolls to... %d\n", dice);

        // Asking for token number
        if(AskToken(chance, dice))
        {
            loop:
            wprintf(L"Token number: ");
            wscanf(L"%d", &tokn);
            tokn -= 1;
        }
        else
            tokn = 0;

        // Moving the pieces
        if(chance == 1)
        {
            if(dice != 6 && Red.OnBoard == 0)
            {
                wprintf(L"\nThe dice doesn't roll to 6..."); 
                asked = 0;
                Sleep(2000);
            }
            else if(Red.Token[tokn] > 71 && dice == 6)
            {
                Red.Token[tokn] = 8;
                Red.OnBoard++;
            }
            else if((Red.Token[tokn] + dice) > 56+1)
            {
                wprintf(L"\nCan't move this token !!");
                Sleep(2000);
                SmoothClean();
                if(Red.OnBoard > 1)
                    goto loop;
            }
            else if(Red.Token[tokn] == 6)
            {
                Red.Token[tokn] = 52;
                Red.Token[tokn] += (dice-1);
            } 
            else if(Red.Token[tokn]+dice > 6 && Red.Token[tokn] <= 6)
            {
                dice = dice - (6-Red.Token[tokn]);
                Red.Token[tokn] = 52;
                dice -= 1;
                Red.Token[tokn] += dice;
            } 
            else if(Red.Token[tokn]+dice > 51 && Red.Token[tokn] <= 51)
            {
                dice = dice - (51-Red.Token[tokn]);
                Red.Token[tokn] = 0;
                dice -= 1;
                Red.Token[tokn] += dice;
            }
            else
                Red.Token[tokn] += dice;
            Position = Red.Token[tokn];
        }
        else if(chance == 2)
        {
            if(dice != 6 && Blue.OnBoard == 0)
            {
                wprintf(L"\nThe dice doesn't roll to 6...");
                asked = 0;
                Sleep(2000);
            }
            else if(Blue.Token[tokn] > 71 && dice == 6)
            {
                Blue.Token[tokn] = 21;
                Blue.OnBoard++;
            }
            else if((Blue.Token[tokn] + dice) > 61+1)
            {
                wprintf(L"\nCan't move this token !!");
                Sleep(2000);
                SmoothClean();
                if(Blue.OnBoard > 1)
                    goto loop;
            }
            else if(Blue.Token[tokn]+dice > 19 && Blue.Token[tokn] <= 19)
            {
                dice = dice - (19-Blue.Token[tokn]);
                Blue.Token[tokn] = 57;
                dice -= 1;
                Blue.Token[tokn] += dice;
            } 
            else if(Blue.Token[tokn]+dice > 51 && Blue.Token[tokn] <= 51)
            {
                dice = dice - (51-Blue.Token[tokn]);
                Blue.Token[tokn] = 0;
                dice -= 1;
                Blue.Token[tokn] += dice;
            }
            else
                Blue.Token[tokn] += dice;
            Position = Blue.Token[tokn];
        }
        else if(chance == 3)
        {
            if(dice != 6 && Yellow.OnBoard == 0)
            {
                wprintf(L"\nThe dice doesn't roll to 6...");
                asked = 0;
                Sleep(2000);
            }
            else if(Yellow.Token[tokn] > 71 && dice == 6)
            {
                Yellow.Token[tokn] = 34;
                Yellow.OnBoard++;
            }
            else if((Yellow.Token[tokn] + dice) > 66+1)
            {
                wprintf(L"\nCan't move this token !!");
                Sleep(2000);
                SmoothClean();
                if(Yellow.OnBoard > 1)
                    goto loop;
            }
            else if(Yellow.Token[tokn]+dice > 32 && Yellow.Token[tokn] <= 32)
            {
                dice = dice - (32-Yellow.Token[tokn]);
                Yellow.Token[tokn] = 62;
                dice -= 1;
                Yellow.Token[tokn] += dice;
            } 
            else if(Yellow.Token[tokn]+dice > 51 && Yellow.Token[tokn] <= 51)
            {
                dice = dice - (51-Yellow.Token[tokn]);
                Yellow.Token[tokn] = 0;
                dice -= 1;
                Yellow.Token[tokn] += dice;
            }
            else
                Yellow.Token[tokn] += dice;
            Position = Yellow.Token[tokn];
        }
        else if(chance == 4)
        {
            if(dice != 6 && Green.OnBoard == 0)
            {
                wprintf(L"\nThe dice doesn't roll to 6...");
                asked = 0;
                Sleep(2000);
            }
            else if(Green.Token[tokn] > 71 && dice == 6)
            {
                Green.Token[tokn] = 47;
                Green.OnBoard++;
            }
            else if((Green.Token[tokn] + dice) > 71+1)
            {
                wprintf(L"\nCan't move this token !!");
                Sleep(2000);
                SmoothClean();
                if(Green.OnBoard > 1)
                    goto loop;
            }
            else if(Green.Token[tokn]+dice > 45 && Green.Token[tokn] <= 45)
            {
                dice = dice - (45-Green.Token[tokn]);
                Green.Token[tokn] = 67;
                dice -= 1;
                Green.Token[tokn] += dice;
            } 
            else if(Green.Token[tokn]+dice > 51 && Green.Token[tokn] <= 51)
            {
                dice = dice - (51-Green.Token[tokn]);
                Green.Token[tokn] = 0;
                dice -= 1;
                Green.Token[tokn] += dice;
            }
            else
                Green.Token[tokn] += dice;
            Position = Green.Token[tokn];
        }

        // Printing moved token
        if(asked)
        {
            wprintf(L"\nMoved token %d !\n", tokn+1);
            Sleep(2000);
        }

        // Checking for passed tokens
        if(chance == 1 && (Red.Token[tokn] > 56 && Red.Token[tokn] < 72))
        {
            Red.Passed++;
            if(Red.Passed == 4)
            {
                ColorPassed++;
                for(int j = 0; j < 4; j++)
                {
                    if(Results[j] == ' ');
                        Results[j] = 'R';
                }
            }
            Red.OnBoard--;
            Red.Token[tokn] = 100;
        }
        else if(chance == 2 && (Blue.Token[tokn] > 61 && Blue.Token[tokn] < 76))
        {
            Blue.Passed++;
            if(Blue.Passed == 4)
            {
                ColorPassed++;
                for(int j = 0; j < 4; j++)
                {
                    if(Results[j] == ' ');
                        Results[j] = 'B';
                }
            }
            Blue.OnBoard--;
            Blue.Token[tokn] = 100;
        }
        else if(chance == 3 && (Yellow.Token[tokn] > 66 && Yellow.Token[tokn] < 80))
        {
            Yellow.Passed++;
            if(Yellow.Passed == 4)
            {
                ColorPassed++;
                for(int j = 0; j < 4; j++)
                {
                    if(Results[j] == ' ');
                        Results[j] = 'Y';
                }
            }
            Yellow.OnBoard--;
            Yellow.Token[tokn] = 100;
        }
        else if(chance == 4 && (Green.Token[tokn] > 71 && Green.Token[tokn] < 84))
        {
            Green.Passed++;
            if(Green.Passed == 4)
            {
                ColorPassed++;
                for(int j = 0; j < 4; j++)
                {
                    if(Results[j] == ' ');
                        Results[j] = 'G';
                }
            }
            Green.OnBoard--;
            Green.Token[tokn] = 100;
        }
 
        // Cutting tokens
        coordinates = ReturnPositions(Position);
        if(coordinates[0] == 1 && chance != 1)
        {
            for(int i = 0; i < 4; i++)
            {
                if(Red.Token[i] == Position)
                {
                    Red.Token[i] = 72+i;
                    wprintf(L"\nRed's Token %d dies !", i+1);
                    wprintf(L"\nYou get a bonus chance !");
                    chance--;
                    break;
                }
            }
        }
        else if(coordinates[1] == 1 && chance != 2)
        {
            for(int i = 0; i < 4; i++)
            {
                if(Blue.Token[i] == Position)
                {
                    Blue.Token[i] = 76 + i;
                    wprintf(L"\nBlue's Token %d dies !", i+1);
                    wprintf(L"\nYou get a bonus chance !");
                    chance--;
                    break;
                }
            }
        }
        else if(coordinates[2] == 1 && chance != 3)
        {
            for(int i = 0; i < 4; i++)
            {
                if(Yellow.Token[i] == Position)
                {
                    Yellow.Token[i] = 80 + i;
                    wprintf(L"\nYellow's Token %d dies !", i+1);
                    wprintf(L"\nYou get a bonus chance !");
                    chance--;
                    break;
                }
            }
        }
        else if(coordinates[3] == 1 && chance != 4)
        {
            for(int i = 0; i < 4; i++)
            {
                if(Green.Token[i] == Position)
                {
                    Green.Token[i] = 84+i;
                    wprintf(L"\nYellow's Token %d dies !", i+1);
                    wprintf(L"\nYou get a bonus chance !");
                    chance--;
                    break;
                }
            }
        }

        // Exiting the game
        if(ColorPassed == 3)
        {
            wprintf(L"\n    GAME OVER    ");
            Sleep(2000);
            break;
        }

        chance++;
        wprintf(L"\e[0;0H");
    }
    system("cls || clear");
    PRINTBOARD();
    wprintf(L"\n┌─────────────────┐");
    wprintf(L"\n| >>  %c WON   << |", Results[0]);
    wprintf(L"\n| Second  >>> %c  |", Results[1]);
    wprintf(L"\n| Third   >>> %c  |", Results[2]);
    wprintf(L"\n| Fourth  >>> %c  |", Results[3]);
    wprintf(L"\n└─────────────────┘");

    return 0;
}

int *ReturnPositions(int position)
{
    int* arr = malloc(4 * sizeof(int));
    if (arr == NULL)
        wprintf(L"\nwe ran into an error !");

    arr[0] = arr[1] = arr[2] = arr[3] = 0;
    for(int i = 0; i < 4; i++)
    {
        if(Red.Token[i] == position)
            arr[0]++;

    }
    for(int i = 0; i < 4; i++)
    {
        if(Blue.Token[i] == position)
            arr[1]++;
    }
    for(int i = 0; i < 4; i++)
    {
        if(Yellow.Token[i] == position)
            arr[2]++;
    }
    for(int i = 0; i < 4; i++)
    {
        if(Green.Token[i] == position)
            arr[3]++;
    }

    return arr;
}
int AskToken(int chance, int dice)
{
    int ask = 0;
    if((chance == 1 && Red.OnBoard == 0) || (chance == 2 && Blue.OnBoard == 0) || (chance == 3 && Yellow.OnBoard == 0) || (chance == 4 && Green.OnBoard == 0))
        ask = 0;
    else if(dice == 6 && ((chance == 1 && Red.Passed < 3) || (chance == 2 && Blue.Passed < 3) || (chance == 3 && Yellow.Passed < 3) || (chance == 4 && Green.Passed < 3)))
        ask = 1;
    else if((chance==1 && Red.OnBoard > 1) || (chance==2 && Blue.OnBoard > 1) || (chance==3 && Yellow.OnBoard > 1) || (chance==4 && Green.OnBoard > 1))
        ask = 1;

    return ask;
}
void SmoothClean()
{
    setlocale(LC_ALL, "");
    set_wide_stream(stdout);
    wprintf(L"\e[33;0H");
    wprintf(L"                                                               ");
    wprintf(L"\e[34;0H                                                      ");
    wprintf(L"\e[35;0H                                                      ");
    wprintf(L"\e[36;0H                                                   ");
    wprintf(L"\e[37;0H                                          ");
    wprintf(L"\e[38;0H                                                  ");
    wprintf(L"\e[39;0H                                                  ");
    wprintf(L"\e[40;0H                                                  ");
    wprintf(L"\e[41;0H                                                  ");
    wprintf(L"\e[42;0H                                                  ");
    wprintf(L"\e[43;0H                                                  ");
    wprintf(L"\e[44;0H                                                  ");
    wprintf(L"\e[33;0H");
}
void PrintTurn(int chance)
{
    if(chance==1)
        wprintf(L"\n\n      --# RED's TURN #--       ");
    else if(chance == 2)
        wprintf(L"\n\n      --# BLUE's TURN #--      ");
    else if(chance == 3)
        wprintf(L"\n\n      --# YELLOW's TURN #--      ");
    else if(chance == 4)
        wprintf(L"\n\n      --# GREEN's TURN #--      ");
}
void INITIALIZATION()
{
    // RED TOKENS
    for(int i = 0; i < 4; i++)
        Red.Token[i] = 72 + i;

    // BLUE TOKENS
    for(int i = 0; i < 4; i++)
        Blue.Token[i] = 76 + i;

    // YELLOW TOKENS
    for(int i = 0; i < 4; i++)
        Yellow.Token[i] = 80 + i;

    // GREEN TOKENS
    for(int i = 0; i < 4; i++)
        Green.Token[i] = 84 + i;

    // Initializing OnBoard variable
    Red.OnBoard = 0;
    Blue.OnBoard = 0;
    Yellow.OnBoard = 0;
    Green.OnBoard = 0;

    // Initializing Passed variable
    Red.Passed = 0;
    Blue.Passed = 0;
    Yellow.Passed = 0;
    Green.Passed = 0;
}
void PRINTBOARD()
{
    setlocale(LC_ALL, "");
    set_wide_stream(stdout);
    wprintf(L"\n┌───────────────────────┬───┬───┬───┬───────────────────────┐");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[5], board[6], board[7]);
    wprintf(L"\n│   ┌───┐       ┌───┐   ├───┼───┼───┤   ┌───┐       ┌───┐   │");
    wprintf(L"\n│   │ %c │       │ %c │   │ %c │ %c │ %c │   │ %c │       │ %c │   │", board[84], board[85], board[4], board[52], board[8], board[72], board[73]);
    wprintf(L"\n│   └───┘       └───┘   ├───┼───┼───┤   └───┘       └───┘   │");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[3], board[53], board[9]);
    wprintf(L"\n│           G           ├───┼───┼───┤           R           │");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[2], board[54], board[10]);
    wprintf(L"\n│   ┌───┐       ┌───┐   ├───┼───┼───┤   ┌───┐       ┌───┐   │");
    wprintf(L"\n│   │ %c │       │ %c │   │ %c │ %c │ %c │   │ %c │       │ %c │   │", board[86], board[87], board[1], board[55], board[11], board[74], board[75]);
    wprintf(L"\n│   └───┘       └───┘   ├───┼───┼───┤   └───┘       └───┘   │");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[0], board[56], board[12]);
    wprintf(L"\n├───┬───┬───┬───┬───┬───┼───┴───┴───┼───┬───┬───┬───┬───┬───┤");
    wprintf(L"\n│ %c │ %c │ %c │ %c │ %c │ %c │\\   R-%d   /│ %c │ %c │ %c │ %c │ %c │ %c │", board[46], board[47], board[48], board[49], board[50], board[51], Red.Passed, board[13], board[14], board[15], board[16], board[17], board[18]);
    wprintf(L"\n├───┼───┼───┼───┼───┼───┤  \\ _ _ /  ├───┼───┼───┼───┼───┼───┤");
    wprintf(L"\n│ %c │ %c │ %c │ %c │ %c │ %c │G-%d _|_ B-%d│ %c │ %c │ %c │ %c │ %c │ %c │", board[45], board[67], board[68], board[69], board[70], board[71], Green.Passed, Blue.Passed, board[61], board[60], board[59], board[58], board[57], board[19]);
    wprintf(L"\n├───┼───┼───┼───┼───┼───┤  /     \\  ├───┼───┼───┼───┼───┼───┤");
    wprintf(L"\n│ %c │ %c │ %c │ %c │ %c │ %c │/   Y-%d   \\│ %c │ %c │ %c │ %c │ %c │ %c │", board[44], board[43], board[42], board[41], board[40], board[39], Yellow.Passed, board[25], board[24], board[23], board[22], board[21], board[20]);
    wprintf(L"\n├───┴───┴───┴───┴───┴───┼───┬───┬───┼───┴───┴───┴───┴───┴───┤");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[38], board[66], board[26]);
    wprintf(L"\n│   ┌───┐       ┌───┐   ├───┼───┼───┤   ┌───┐       ┌───┐   │");
    wprintf(L"\n│   │ %c │       │ %c │   │ %c │ %c │ %c │   │ %c │       │ %c │   │", board[80], board[81], board[37], board[65], board[27], board[76], board[77]);
    wprintf(L"\n│   └───┘       └───┘   ├───┼───┼───┤   └───┘       └───┘   │");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[36], board[64], board[28]);
    wprintf(L"\n│           Y           ├───┼───┼───┤           B           │");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[35], board[63], board[29]);
    wprintf(L"\n│   ┌───┐       ┌───┐   ├───┼───┼───┤   ┌───┐       ┌───┐   │");
    wprintf(L"\n│   │ %c │       │ %c │   │ %c │ %c │ %c │   │ %c │       │ %c │   │", board[82], board[83], board[34], board[62], board[30], board[78], board[79]);
    wprintf(L"\n│   └───┘       └───┘   ├───┼───┼───┤   └───┘       └───┘   │");
    wprintf(L"\n│                       │ %c │ %c │ %c │                       │", board[33], board[32], board[31]);
    wprintf(L"\n└───────────────────────┴───┴───┴───┴───────────────────────┘");
}
void ModifyBoard()
{
    for(int j = 0; j < 88; j++)
        board[j] = ' ';
    for(int i = 0; i < 88; i++)
    {
        if(i == Red.Token[0] || i == Red.Token[1] || i == Red.Token[2] || i == Red.Token[3])
            board[i] = 'R';
        else if(i == Blue.Token[0] || i == Blue.Token[1] || i == Blue.Token[2] || i == Blue.Token[3])
            board[i] = 'B';
        else if(i == Yellow.Token[0] || i == Yellow.Token[1] || i == Yellow.Token[2] || i == Yellow.Token[3])
            board[i] = 'Y';
        else if(i == Green.Token[0] || i == Green.Token[1] || i == Green.Token[2] || i == Green.Token[3])
            board[i] = 'G';
    }
}