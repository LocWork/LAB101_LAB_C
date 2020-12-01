#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int MAX = 100;
void userPrompt(int * row, int * col);
void userInput(int row, int col, int aMatrix[][MAX]);
void calculate(int row, int col, int aMatrix[][MAX], int bMatrix[][MAX]);
//int calculateTwo(int aMatrix[][MAX], int bMatrix[][MAX],int i, int j);
void printArray(int row, int col,int cMatrix[][MAX]);
int main()
{
    //field
    int aMatrix[MAX][MAX];
    int bMatrix[MAX][MAX];
    int cMatrix[MAX][MAX];
    int row, col;
    int choice;

    //main code area
    do
    {
        userPrompt(&row, &col);
        userInput(row, col, aMatrix);
        userInput(row, col, bMatrix);
        calculate(row, col, aMatrix, bMatrix);
        printArray(row, col, aMatrix);
        do
        {
            printf("Press 1 to continue or 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);


    return 0;
}

//MENU
void userPrompt(int * row, int * col)
{
    do
    {
        printf("Accept size: ");
        scanf("%d%d", row, col);
    }while(*row < 1 || *row > MAX || *col < 1 || * col > MAX);
}

//user matrix
void userInput(int row, int col, int aMatrix[][MAX])
{
    int totalMatrix;
    puts("Accept matrix: ");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            scanf("%d", &aMatrix[i][j]);
        }
    }
}


void calculate(int row, int col, int aMatrix[][MAX], int bMatrix[][MAX])
{
    //neu can store de debug
    //int store;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            aMatrix[i][j] = aMatrix[i][j] + bMatrix[i][j];

        }
    }

}



void printArray(int row, int col, int cMatrix[][MAX])
{
    //neu can store de debug
    //int store;
    puts("m = m1 + m2");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d\t",cMatrix[i][j]);
        }
        printf("\n");
    }
}

//int calculateTwo(int aMatrix[][MAX], int bMatrix[][MAX], int i , int j )
//{
//    int dMatrix[MAX][MAX];
//    dMatrix[i][j] = aMatrix[i][j] + bMatrix[i][j];
//    return dMatrix[i][j];
//}

//    puts("m = m1 + m2");
//    for(int i = 0; i < row; i++)
//    {
//        for(int j = 0; j < col; j++)
//        {
//            totalMatrix = calculateTwo(aMatrix, bMatrix, i, j);
//            printf("%d\t", totalMatrix);
//        }
//        printf("\n");
//    }
//}
