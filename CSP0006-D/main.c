#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
void ascSort(int * a, int n);
void descSort(int * a, int n);
void userInput(int * a, int * n);
void printArray(int * a, int n);

int main()
{
    //fields
    int a[MAX];
    int number;
    int choice;
    //Methods
    do{
        userInput(a, &number);
        ascSort(a, number);
        printf("array sorted in ascending:\n");
        printArray(a, number);
        descSort(a, number);
        printf("\narray sorted in descending:\n");
        printArray(a, number);
        //exit or continue
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
        printf("Please enter the size of array: ");
        scanf("%d", n);
    }while(*n < 1 || *n > 100);

    //input element
    for(int i = 0; i < *n ;i++)
    {
        printf("Enter element[%d]: ", i);
        scanf("%d", (a + i));
    }
}

void ascSort(int * a, int n)
{
    //asc sort
    for(int i = 0; i < n - 1 ; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
           {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
           }
        }
    }

}

void descSort(int * a , int n)
{
        //desc sort
        for(int i = 0; i < n - 1 ; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
           {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
           }
        }
    }
}

void printArray(int * a, int n)
{
        for(int i = 0; i < n; i++)
    {
        printf("%d\t", *(a + i));
    }
}


