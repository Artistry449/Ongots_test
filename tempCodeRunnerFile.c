#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Size
#define SIZE 20
// All arrays
char myBoard1[SIZE][SIZE],
    enemyBoard1[SIZE][SIZE],
    myBoard2[SIZE][SIZE],
    enemyBoard2[SIZE][SIZE];

void makeBoard()
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            myBoard1[i][j] = ' ';
            enemyBoard1[i][j] = ' ';
            myBoard2[i][j] = ' ';
            enemyBoard2[i][j] = ' ';
        }
    }
}

bool Deesh(char p[SIZE][SIZE], int x, int y, bool a)
{
    if (p[x + 1][y] == ' ' && p[x + 2][y] == ' ' && p[x + 3][y] == ' ' && p[x + 1][y - 1] == ' ' && p[x + 1][y + 1] == ' ' && p[x + 3][y - 1] == ' ' && p[x + 3][y + 1] == ' ')
    {
        p[x][y] = 'T';
        p[x + 1][y] = 'B';
        p[x + 2][y] = 'B';
        p[x + 3][y] = 'B';
        p[x + 1][y - 1] = 'B';
        p[x + 1][y + 1] = 'B';
        p[x + 3][y - 1] = 'B';
        p[x + 3][y + 1] = 'B';
        a = true;
    }
    return a;
}
bool Doosh(char p[SIZE][SIZE], int x, int y, bool a)
{
    if (p[x - 1][y] == ' ' && p[x - 2][y] == ' ' && p[x - 3][y] == ' ' && p[x - 1][y - 1] == ' ' && p[x - 1][y + 1] == ' ' && p[x - 3][y - 1] == ' ' && p[x - 3][y + 1] == ' ')
    {
        p[x][y] = 'T';
        p[x - 1][y] = 'B';
        p[x - 2][y] = 'B';
        p[x - 3][y] = 'B';
        p[x - 1][y - 1] = 'B';
        p[x - 1][y + 1] = 'B';
        p[x - 3][y - 1] = 'B';
        p[x - 3][y + 1] = 'B';
        a = true;
    }
    return a;
}
bool Zuun(char p[SIZE][SIZE], int x, int y, bool a)
{
    if (p[x][y + 1] == ' ' && p[x][y + 2] == ' ' && p[x][y + 3] == ' ' && p[x + 1][y + 1] == ' ' && p[x - 1][y + 1] == ' ' && p[x + 1][y + 3] == ' ' && p[x - 1][y + 3] == ' ')
    {
        p[x][y] = 'T';
        p[x][y + 1] = 'B';
        p[x][y + 2] = 'B';
        p[x][y + 3] = 'B';
        p[x - 1][y + 1] = 'B';
        p[x + 1][y + 1] = 'B';
        p[x - 1][y + 3] = 'B';
        p[x + 1][y + 3] = 'B';
        a = true;
    }
    return a;
}
bool Baruun(char p[SIZE][SIZE], int x, int y, bool a)

{
    if (p[x][y - 1] == ' ' && p[x][y - 2] == ' ' && p[x][y - 3] == ' ' && p[x + 1][y - 1] == ' ' && p[x - 1][y - 1] == ' ' && p[x + 1][y - 3] == ' ' && p[x - 1][y - 3] == ' ')
    {
        p[x][y] = 'T';
        p[x][y - 1] = 'B';
        p[x][y - 2] = 'B';
        p[x][y - 3] = 'B';
        p[x - 1][y - 1] = 'B';
        p[x + 1][y - 1] = 'B';
        p[x - 1][y - 3] = 'B';
        p[x + 1][y - 3] = 'B';
        a = true;
    }
    return a;
}
void addPlane(char plane[SIZE][SIZE], int planeNum)
{
    int x, y, z;
    bool a;
    srand(time(NULL));
    for (int i = 0; i < planeNum; i++)
    {
        a = false;
        while (a == false)
        {
            x = rand() % 20;
            y = rand() % 20;

            if (x != 0 && y != 19 || x != 0 && y != 0 || x != 19 && y != 19 || x != 19 && y != 0)
            {
                if (plane[x][y] == ' ' && x != 0 && y != 0)
                {
                    a = true;
                }
            }
        }
        a = false;
        while (a == false)
        {
            z = rand() % 5;
            switch (z)
            {
            case 1:
                a = Deesh(plane, x, y, a);
                break;
            case 2:
                a = Doosh(plane, x, y, a);
                break;
            case 3:
                a = Zuun(plane, x, y, a);
                break;
            case 4:
                a = Baruun(plane, x, y, a);
                break;
            }
        }
    }
}
void DrawBoard(char data1[SIZE][SIZE], char data2[SIZE][SIZE])
{
    int i, iX, iY;
    printf("%40s%104s\n", "My board", "my shot board");

    for (i = 0; i < 45; i++)
    {
        if (i > 19 && i < 25)
            if (i == 20)
                printf("       ");
            else
                printf("    ");
        else if (i == 0)
            printf("    %d  ", i + 1);
        else if (i == 25)
            printf(" %d  ", i - 24);
        else if (i < 20)
        {
            if (i == 10)
                printf(" %d", i + 1);
            else if (i > 10)
                printf(" %d ", i + 1);
            else
                printf(" %d  ", i + 1);
        }
        else
        {
            if (i == 25)
                printf("  %d  ", i - 24);
            else if (i - 24 > 9)
                printf(" %d ", i - 24);
            else
                printf(" %d  ", i - 24);
        }
    }
    printf("\n");
    for (i = 0; i < 45; i++)
    {
        if (i > 19 && i < 25)
            printf("    ");
        else if (i == 0 || i == 25)
            printf("  +---+");
        else
            printf("---+");
    }
    printf("\n");
    for (iY = 0; iY < 20; iY++)
    {
        for (iX = 0; iX < 45; iX++)
        {
            if (iX > 19 && iX < 25)
                printf("    ");
            else if (iX == 0)
            {
                if (iY < 9)
                    printf(" %d| %c |", iY + 1, data1[iY][iX]);
                else
                    printf("%d| %c |", iY + 1, data1[iY][iX]);
            }
            else if (iX == 25)
            {
                if (iY < 9)
                    printf(" %d| %c |", iY + 1, data2[iY][iX]);
                else
                    printf("%d| %c |", iY + 1, data2[iY][iX]);
            }
            else if (iX > 0 && iX < 20)
                printf(" %c |", data1[iY][iX]);
            else
                printf(" %c |", data2[iY][iX - 25]);
        }
        printf("\n");
        for (i = 0; i < 45; i++)
        {
            if (i > 19 && i < 25)
                printf("    ");
            else if (i == 0 || i == 25)
                printf("  +---+");
            else
                printf("---+");
        }
        printf("\n");
    }
}
char fire(int y, int x, char myBoard[SIZE][SIZE], char enemyBoard[SIZE][SIZE])
{
    int i, j;
    // togloch hooson zai onsoh tohoildol
    if (enemyBoard[x][y] == ' ')
    {
        myBoard[x][y] = 'H';
        return 'H';
    }
    // toglogch daisnii pngotsnii tolgoig onon ongotsiig sunsuusuh punkts
    else if (enemyBoard[x][y] == 'T')
    {
        myBoard[x][y] = 'X';
        return 'X';
    }
    // toglogch daisnii ongotsiig onon sharhaduulsan tohoildol
    else if (enemyBoard[x][y] == 'B')
    {
        myBoard[x][y] = 'S';
        return 'S';
    }
    // toglogch umnu n buudsan gazraa buudsan tohoildol
    else
    {
        return 'R';
    }
}
int main()
{
    printf("\n---WELCOME TO PLANE-SHOOTING GAME---\n");
    printf("      ---TOGLOOMIIN DUREM---\n\n");

    makeBoard();

    int planeNum, planeNum1, planeNum2, shootX, shootY;
    char isDestroyed;

    printf("Ongotsnii shirheg: ");
    scanf("%d", &planeNum);

    planeNum1 = planeNum;
    planeNum2 = planeNum;

    addPlane(myBoard1, planeNum1);
    addPlane(myBoard2, planeNum2);

    // printf("\nPLAYER 1 SHOOTING: ");
    // printf("\nPLAYER 2 SHOOTING: ");
    // player 1 window

    while (planeNum1 != 0 && planeNum2 != 0)
    {
        printf("PLAYER 1\n\n");
        DrawBoard(myBoard1, enemyBoard1);
        printf("\nbuudah coordinataa oruulan uu \nX=");
        scanf("%d", &shootX);
        printf("\nbuudah coordinataa oruulan uu \nY=");
        scanf("%d", &shootY);

        isDestroyed = fire(shootX - 1, shootY - 1, enemyBoard1, myBoard2);
        DrawBoard(myBoard1, enemyBoard1);

        printf(" PLAYER 1 DESTROYED PLANES: %d", planeNum - planeNum2);
        if (isDestroyed == 'X')
        {
            planeNum2 = planeNum2 - 1;
        }
        if (planeNum2 == 0)
        {
            printf("\n---PLAYER 1 WON\n");
            break;
        }
        printf("\n");
        // get space
        printf("\n\n\n\n\n");

        // player 2 window
        printf("PLAYER 2\n\n");
        DrawBoard(myBoard2, enemyBoard2);
        printf("\nbuudah coordinataa oruulan uu \nX=");
        scanf("%d", &shootX);
        printf("\nbuudah coordinataa oruulan uu \nY=");
        scanf("%d", &shootY);

        isDestroyed = fire(shootX - 1, shootY - 1, enemyBoard2, myBoard1);
        DrawBoard(myBoard2, enemyBoard2);
        if (isDestroyed == 'X')
        {
            planeNum1 = planeNum1 - 1;
        }
        printf(" PLAYER 2 DESTROYED PLANES: %d", planeNum - planeNum1);
        if (planeNum1 == 0){
            printf("\n---PLAYER 2 WON\n");
            break;
        }
        
    }
}