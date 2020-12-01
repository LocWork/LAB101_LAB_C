#include <stdio.h>
#include <stdlib.h>
const int MAX = 10;
void userPrompt();
void userInput(int * a, int * n);
int evenSum(int * a, int n);
int oddSum(int * a, int n);
void printSum(int even, int odd);
int main()
{
    int a[MAX];
    int arraySize;
    int totalEven, totalOdd;
    int choice;
    do
    {
        userPrompt();
        userInput(a, &arraySize);
        totalEven = evenSum(a, arraySize);
        totalOdd = oddSum(a, arraySize);
        printSum(totalEven,totalOdd);
        do
        {
            printf("\nPress 1 to continue, 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);
    return 0;
}

void userPrompt()
{
    printf("Sum Even Odd program\n");
}

void userInput(int * a, int * n)
{
    do
    {
        printf("Enter a number of element n= ");
        scanf("%d", n);
    }while(*n < 1 || *n > MAX);

    printf("Input elements:\n");
    for(int i = 0; i < *n; i++)
    {
        printf("\tElement %d: ", i + 1);
        scanf("%d", (a + i));
    }
}

int evenSum(int * a, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            sum = sum + a[i];
        }
    }
    return sum;
}

int oddSum(int * a, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 != 0)
        {
            sum = sum + a[i];
        }
    }
    return sum;
}

void printSum(int even, int odd)
{
    printf("Sum of Even= %d\n", even);
    printf("Sum of Odd= %d", odd);
}
