#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
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
=======
// Board-nii hemjee 20x20
#define SIZE 20
// Board-iig coordinattai ni hewleh
void DrawBoard(char data1[][20], char data2[][20]){
    int i, iX, iY;
    printf("%40s%106s\n", "PLAYER 1", "PLAYER 2");
    for(i = 0; i < 45; i++){
        if(i > 19 && i < 25)
            if( i == 20) printf("       ");
            else  printf("    ");
        else if(i == 0 ) printf("    %d  ", i+1);
        else if(i == 25) printf(" %d  ", i-24);
        else if(i < 20){
            if(i == 10) printf(" %d", i+1);
            else if ( i > 10) printf(" %d ", i+1);
            else printf(" %d  ", i+1);
        }
        else {
            if ( i == 25 ) printf("  %d  ", i-24);
            else if( i-24 > 9) printf(" %d ", i-24);
            else printf(" %d  ", i-24);
        }
    }
    printf("\n");
    for(i = 0; i < 45; i++){
        if(i > 19 && i < 25) printf("    ");
        else if(i == 0 || i == 25) printf("  +---+");
        else printf("---+");
    }
    printf("\n");
    for(iY = 0; iY < 20; iY++){ 
        for(iX = 0; iX < 45; iX++){
            if(iX > 19 && iX < 25) printf("    ");
            else if(iX == 0){
                if(iY < 9) printf(" %d| %c |",iY+1, data1[iY][iX]);
                else printf("%d| %c |",iY+1, data1[iY][iX]);
            }
            else if(iX == 25){
                if(iY < 9) printf(" %d| %c |",iY+1, data1[iY][iX]);
                else printf("%d| %c |",iY+1, data1[iY][iX]);
            }
            else if(iX > 0 && iX < 20) printf(" %c |", data1[iY][iX]);
            else printf(" %c |", data2[iY][iX-25]);
        }
        printf("\n");
        for(i = 0; i < 45; i++){
            if(i > 19 && i < 25) printf("    ");
            else if(i == 0 || i == 25) printf("  +---+");
            else printf("---+");
        }
        printf("\n");
    }

}
char fire(int x, int y, int myPlaneNum, int myBoard[][20], int enemyBoard[][20]){
    int i, j;
    //togloch hooson zai onsoh tohoildol
    if(enemyBoard[x][y] == " "){
        myBoard[x][y] = 'H';
        return 'H';
    }
    //toglogch daisnii pngotsnii tolgoig onon ongotsiig sunsuusuh punkts
    else if(enemyBoard[x][y] == "T"){
        myBoard[x][y] = 'X';
        return 'X';
    }
    //toglogch daisnii ongotsiig onon sharhaduulsan tohoildol
    else if(enemyBoard[x][y] == "B"){
        myBoard[x][y] == "S";
        return 'S';
    }
    //toglogch umnu n buudsan gazraa buudsan tohoildol
    else {
        return 'R';
>>>>>>> 7ce139df3d2c626f7b90612d29fbe32e865befb9
    }
}
bool Deesh(char p[SIZE][SIZE], int x, int y, bool a)
{
    if (p[x + 1][y] == ' ' && p[x + 2][y] == ' ' && p[x + 3][y] == ' ' && p[x + 1][y - 1] == ' ' && p[x + 1][y + 1] == ' ' && p[x + 3][y - 1] == ' ' && p[x + 3][y + 1] == ' ')
    {
        if (x + 3 <= 19 && y - 1 >= 0 && y + 1 <= 19)
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
    }
    return a;
}
bool Doosh(char p[SIZE][SIZE], int x, int y, bool a)
{
    if (p[x - 1][y] == ' ' && p[x - 2][y] == ' ' && p[x - 3][y] == ' ' && p[x - 1][y - 1] == ' ' && p[x - 1][y + 1] == ' ' && p[x - 3][y - 1] == ' ' && p[x - 3][y + 1] == ' ')
    {
        if (x - 3 >= 0 && y - 1 >= 0 && y + 1 <= 19)
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
    }
    return a;
}
<<<<<<< HEAD
bool Zuun(char p[SIZE][SIZE], int x, int y, bool a)
{
    if (p[x][y + 1] == ' ' && p[x][y + 2] == ' ' && p[x][y + 3] == ' ' && p[x + 1][y + 1] == ' ' && p[x - 1][y + 1] == ' ' && p[x + 1][y + 3] == ' ' && p[x - 1][y + 3] == ' ')
    {
        if (y + 3 <= 19 && x - 1 >= 0 && x + 1 <= 19)
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
    }
    return a;
}
bool Baruun(char p[SIZE][SIZE], int x, int y, bool a)

{
    if (p[x][y - 1] == ' ' && p[x][y - 2] == ' ' && p[x][y - 3] == ' ' && p[x + 1][y - 1] == ' ' && p[x - 1][y - 1] == ' ' && p[x + 1][y - 3] == ' ' && p[x - 1][y - 3] == ' ')
    {
        if (y - 3 >= 0 && x - 1 >= 0 && x + 1 <= 19)
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
    }
    return a;
}
void addPlane(char plane[SIZE][SIZE], char plane1[SIZE][SIZE], int planeNum)
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
    for (int i = 0; i < planeNum; i++)
    {
        a = false;
        while (a == false)
        {
            x = rand() % 20;
            y = rand() % 20;

            if (x != 0 && y != 19 || x != 0 && y != 0 || x != 19 && y != 19 || x != 19 && y != 0)
            {
                if (plane1[x][y] == ' ' && x != 0 && y != 0)
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
                a = Deesh(plane1, x, y, a);
                break;
            case 2:
                a = Doosh(plane1, x, y, a);
                break;
            case 3:
                a = Zuun(plane1, x, y, a);
                break;
            case 4:
                a = Baruun(plane1, x, y, a);
                break;
            }
        }
    }
}
void DrawBoard(char data1[SIZE][SIZE], char data2[SIZE][SIZE])
{
    int i, iX, iY;
    printf("%40s%104s\n", "MINII BOARD", "MINII BUUDSAN");

    for (i = 0; i < 45; i++)
    {
        if (i > 19 && i < 25)
            if (i == 20)
                printf("       ");
=======
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
    for (i = 1; i <= SIZE; i++)
    {
        for (j = 1; j <= SIZE; j++)
        {
            plane[i][j] = ' ';
        }
    }
    // Eronhii durem, tanih temdeguud
    printf("\n\n---WELCOME TO PLANE-SHOOTING GAME---\n");
    printf("      ---TOGLOOMIIN DUREM---\n\n");
    printf("1. Ta uuriin ongotsnii coordinate-iig oruulna\n");
    printf("2. Ongotsnii coordinate-iig oruulj buudaj sharhduulna\n");
    printf("3. Herev togloomiig duusgahiig husvel y: 0 x: 0 gj oruulna\n\n");

    printf("T - ongotsnii tolgoi\n");
    printf("B - ongotsnii biy\n");
    printf("X - sonoson\n");
    printf("H - hooson\n");
    printf("S - sharh\n\n");

    // Hereglegchees uusgeh ongotsnii shirheg-iig avah
    printf("Ta heden shirheg ongots oruulah ve?\n");

    printf("Ongotsnii too: ");
    scanf("%d", &planeNum);

    // Uusgeh ongotsnii toog 0 gj oruulval program duusna
    if (planeNum == 0)
        duusgah();
    for (int tooluur = 1; tooluur <= planeNum; tooluur++)
    {
        printf("ongots %d: \n", tooluur);
        // Ongotsnii tolgoin coordinate-uudiig avah
        printf("ongotsnii tolgoi hesgiin coordinate\ny:  ");
        scanf("%d", &Tx);
        printf("x:  ");
        scanf("%d", &Ty);
        // Ongotsnii biyiin coordinate-uudiig avah
        if (Tx == 0 && Ty == 0)
            duusgah();
        printf("ongotsnii biynii hesgiin coordinate-uud: \n");
        for (int tooluurB = 1; tooluurB <= 7; tooluurB++)
        {
            printf("y: ");
            scanf("%d", &Bx);
            printf("x: ");
            scanf("%d", &By);
            // Board-naas tom coordinate-iin tseg oruulsan tohioldold aldaa zaah nohtsol
            while (Bx > SIZE || By > SIZE || Tx > SIZE || Ty > SIZE)
            {
                printf("\nTa coordinate-iig zov oruulna uu!\n");

                printf("ongotsnii tolgoi hesgiin coordinate-iig oruulna uu\ny:  ");
                scanf("%d", &Tx);
                printf("x:  ");
                scanf("%d", &Ty);

                printf("ongotsnii biynii hesgiin coordinate-uudiig oruulna uu\n");
                printf("y: ");
                scanf("%d", &Bx);
                printf("x: ");
                scanf("%d", &By);
            }
            setPlane(plane, Bx, By, Tx, Ty);
        }
        printBoard(plane);
    }
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
>>>>>>> 7ce139df3d2c626f7b90612d29fbe32e865befb9
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
    // x = x-1; y = y-1;
    //  togloch hooson zai onoh tohioldol
    if (enemyBoard[x][y] == ' ')
    {
        myBoard[x][y] = 'H';
        return 'H';
    }
    // toglogch daisnii pngotsnii tolgoig onon ongotsiig sunsuusuh funkts
    else if (enemyBoard[x][y] == 'T')
    {
        myBoard[x][y] = 'X';
        return 'X';
    }
    // toglogch daisnii ongotsiig onon sharhaduulsan tohioldol
    else if (enemyBoard[x][y] == 'B')
    {
        myBoard[x][y] = 'S';
        return 'S';
    }
    // toglogch umnu n buudsan gazraa buudsan tohioldol
    else
        return 'R';
}
void clearScreen()
{
    printf("\033[2J");
    printf("\033[1;1H");
}
int main()
{
    clearScreen();
    printf("\n---WELCOME TO PLANE-SHOOTING GAME---\n");
    printf("      ---TOGLOOMIIN DUREM---\n\n");

    makeBoard();

    int planeNum, planeNum1, planeNum2, shootX, shootY, i, isShiljih = 0;
    char isDestroyed;

    printf("Ongotsnii shirheg: ");
    scanf("%d", &planeNum);

    planeNum1 = planeNum;
    planeNum2 = planeNum;

    addPlane(myBoard1, myBoard2, planeNum1);

    while (planeNum1 != 0 && planeNum2 != 0)
    {

        for (i = 0; i < 3; i++)
        {
            printf("PLAYER 1\n\n");
            DrawBoard(myBoard1, enemyBoard1);
            printf("\nbuudah coordinataa oruulna uu \nX=");
            scanf("%d", &shootX);
            printf("\nbuudah coordinataa oruulna uu \nY=");
            scanf("%d", &shootY);

            isDestroyed = fire(shootX - 1, shootY - 1, enemyBoard1, myBoard2);
            DrawBoard(myBoard1, enemyBoard1);

            printf("---PLAYER 1-IIN USTGASAN ONGOTSNII TOO: %d---", planeNum - planeNum2);
            if (isDestroyed == 'X')
            {
                planeNum2 = planeNum2 - 1;
            }
            if (planeNum2 == 0)
            {
                printf("\n---PLAYER 1 WON\n");
                break;
            }
        }
        if (planeNum2 == 0)
            break;
        printf("\nPLAYER 2-ruu shiljih uu?\nShiljih bol 1 gj oruulna uu...\n");
        scanf("%d", &isShiljih);
        if (isShiljih == 1)
            clearScreen();
        printf("\n");
        // get space
        printf("\n\n\n\n\n");
        // player 2 window
        for (i = 0; i < 3; i++)
        {
            printf("PLAYER 2\n\n");
            DrawBoard(myBoard2, enemyBoard2);
            printf("\nbuudah coordinataa oruulna uu \nX=");
            scanf("%d", &shootX);
            printf("\nbuudah coordinataa oruulna uu \nY=");
            scanf("%d", &shootY);

            isDestroyed = fire(shootX - 1, shootY - 1, enemyBoard2, myBoard1);
            DrawBoard(myBoard2, enemyBoard2);
            if (isDestroyed == 'X')
            {
                planeNum1 = planeNum1 - 1;
            }
            printf("---PLAYER 2-IIN USTGASAN ONGOTSNII TOO: %d---", planeNum - planeNum1);
            if (planeNum1 == 0)
            {
                printf("\n---PLAYER 2 WON\n");
                break;
            }
        }
        if (planeNum1 == 0)
            break;
        isShiljih = 0;
        printf("\nPLAYER 1-ruu shiljih uu?\nShiljih bol 1 gj oruulna uu...\n");
        scanf("%d", &isShiljih);
        if (isShiljih == 1)
            clearScreen();
    }
}