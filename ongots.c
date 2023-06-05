#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//  Board-nii hemjee 10x10
//  Massive 0-ees eheldeg ba board-iig 1-ees ehluulhiin tuld SIZE=11
#define SIZE 21
void DrawBoard(char data1[][20], char data2[][20])
{
    printf("%40s%106s\n", "PLAYER 1", "PLAYER 2");
    for (int i = 0; i < 45; i++)
    {
        if (i > 19 && i < 25)
            printf("    ");
        else if (i == 0 || i == 25)
            printf("+---+");
        else
            printf("---+");
    }
    printf("\n");
    for (int iY = 0; iY < 20; iY++)
    {
        for (int iX = 0; iX < 45; iX++)
        {
            if (iX > 19 && iX < 25)
                printf("    ");
            else if (iX == 0)
                printf("| %c |", data1[iY][iX]);
            else if (iX == 25)
                printf("| %c |", data2[iY][iX - 25]);
            else if (iX > 0 && iX < 20)
                printf(" %c |", data1[iY][iX]);
            else
                printf(" %c |", data2[iY][iX - 25]);
        }
        printf("\n");
        for (int i = 0; i < 45; i++)
        {
            if (i > 19 && i < 25)
                printf("    ");
            else if (i == 0 || i == 25)
                printf("+---+");
            else
                printf("---+");
        }
        printf("\n");
    }
}

void printBoard(char plane[SIZE][SIZE])
{
    int i, j;
    printf("\nBoard: \n  ");

    for (i = 1; i <= 10; i++)
    {
        printf(" %d", i);
    }
    printf("\n");
    for (i = 1; i <= 10; i++)
    {
        if (i < 10)
            printf(" ");
        printf("%d ", i);
        for (j = 1; j <= 10; j++)
        {
            printf("%c ", plane[i][j]);
        }
        printf("\n");
    }
}
// Hereglegch ongotsnii tolgoi, biynii code-iig coordinate-iig oruulah
void setPlane(char plane[SIZE][SIZE], int x, int y, int tolgoiX, int tolgoiY)
{
    plane[x][y] = 'B';
    plane[tolgoiX][tolgoiY] = 'T';
}
// Hereglegch x=0, y=0 gj oruulsan tohioldold togloomiig duusgah
void duusgah()
{
    printf("Togloom duuslaa!");
    exit(0);
}
void AddPlane(char plane[SIZE][SIZE], int planeNum)
{
    int x, y, z;
    bool a;
    srand(time(NULL));
    for (int i = 0; i < planeNum; i++)
    {
        a = false;
        while (a == false)
        {
            x = rand() % 21;
            y = rand() % 21;
            if (plane[x][y] == '.' && x != 0 && y != 0)
            {
                a = true;
            }
        }
        a = false;
        while (a == false)
        {
            z = rand() % 4;
            switch (z)
            {
            case 0:
            break;
            }
        }
    }
}
bool Deesh(char p[SIZE][SIZE], bool a, int x, int y)
{
    // if (p[x + 1][y])
    // {
    // }
}
int main()
{
    // Tx - tolgoin x tenhleg
    // Ty - tolgoin y tenhleg
    // Bx - biyiin x tenhleg
    // By - biyiin y tenhleg

    // planeNum - Hereglegchiin uusgeh ongotsnii too

    // i,j - x,y tenhlegiin davtaltiin tooluuruud
    // n,m - buudah x,y tenhleguud

    int Tcounter = 0, Tx, Ty, Bx, By, planeNum, i, j, n, m;
    char plane[SIZE][SIZE];

    // Board-aa uusgeh
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            plane[i][j] = '.';
        }
    }
    // Eronhii durem, tanih temdeguud
    printf("\n\n---WELCOME TO PLANE-SHOOTING GAME---\n");
    printf("      ---TOGLOOMIIN DUREM---\n\n");
    printf("1. Ta uuriin ongotsnii coordinate-iig oruulna\n");
    printf("2. Ongotsnii coordinate-iig oruulj buudaj sharhduulna\n");
    printf("3. Herev togloomiig duusgahiig husvel y: 0 x: 0 goruulna\n\n");

    printf("T - ongotsnii tolgoi\n");
    printf("B - ongotsnii biy\n");
    printf("X - sonoson\n");
    printf("S - sharh\n\n");

    // Hereglegchees uusgeh ongotsnii shirheg-iig avah
    printf("Ta heden shirheg ongots oruulah ve?\n");

    printf("Ongotsnii too: ");
    scanf("%d", &planeNum);

    // Uusgeh ongotsnii toog 0 gj oruulval program duusna
    if (planeNum == 0)
        duusgah();
    while (100 > 0)
    {
        // Hereglegch ongots buudah
        printf("buudah tseguud: \n");
        printf("y:");
        scanf("%d", &n);
        printf("x:");
        scanf("%d", &m);
        // x=0, y=0 gj oruulsan nohtsold program duusgah nohtsol
        if (n != 0 && m != 0)
        {
            if (n < 11 & m < 11)
            {
                // Ongots sonooson tohioldold sonoson ongotsiig tooloh, T useg tavih
                if (plane[n][m] == 'T')
                {
                    Tcounter += 1;
                    plane[n][m] = 'X';
                    if (Tcounter == planeNum)
                    {
                        printBoard(plane);
                        printf("\nTa hojloo!\nTogloom duuslaa!\n");
                        break;
                    }
                    printBoard(plane);
                }
                // Ongotsnii biyiig onoson tohioldold S useg tavih
                else if (plane[n][m] == 'B')
                {
                    plane[n][m] = 'S';

                    printBoard(plane);
                }
                else
                {
                    printBoard(plane);
                }
            }
            else
            {
                printf("Coordinate-iig zov oruulna uu");
            }
        }
        else
        {
            duusgah();
        }
    }
}
