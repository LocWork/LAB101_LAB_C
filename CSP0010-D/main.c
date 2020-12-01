#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
void userInput(int * a, int * n);
void numberDetecter(int * a, int * n);
void printArray(int * a, int n);
int main()
{
    //fields
    int arraySize;
    int a[MAX];
    int choice;
    //main section
    do
    {
        //main input
        userInput(a, &arraySize);

        //In array ban dau
        printf("The original array:\n");
        printArray(a, arraySize);

        //xoa cac so giong nhau
        numberDetecter(a, &arraySize);
        printf("\nThe array after removing duplicate elements:\n");
        printArray(a, arraySize);
        do
        {
            printf("\nPress 1 to continue, 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);

    return 0;
}

void userInput(int * a, int * n)
{
    do
    {
        printf("Please enter size of array: ");
        scanf("%d", n);
    }while(*n < 1 || *n > MAX);

    for(int i = 0 ; i < *n; i++)
    {
        printf("Element[%d] = ", i);
        scanf("%d", (a + i));
    }
}

void printArray(int * a, int n)
{
    for(int i = 0;i < n; i++)
    {
        printf("%d\t", *(a + i));
    }
}

void numberDetecter(int * a, int * n)
{
    for(int i = 0; i < *n - 1; i++)
    {
        for(int j = i + 1; j < *n; j++)
        {
            if(a[i] == a[j])
            {
                for(int t = j; t < *n; t++)
                {
                  a[t] = a[t + 1];
                }
                j--;
                *n = *n - 1;
            }
        }
    }
}
