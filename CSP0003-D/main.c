#include <stdio.h>
#include <stdlib.h>
const MAX = 100;
void userInput(int * a, int * n);
void ascSort(int * a, int n);
void printArray(int * a, int n);
void newInput(int * a, int *n, int * getNewInput);

int main()
{
    //fields
    int arraySize, newValue;
    int a[MAX];
    int choice;


    //main part
    do
    {
        userInput(a,&arraySize);
        ascSort(a,arraySize);
        printf("The array after sorting:\n");
        printArray(a,arraySize);
        //new array
        newInput(a,&arraySize,&newValue);
        printf("New array:\n");
        ascSort(a,arraySize);
        printArray(a,arraySize);
        do
        {
            printf("\nPress 1 to continue, 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);

    return 0;
}

//user main input
void userInput(int * a, int * n)
{
    do
    {
        printf("Please enter size of array: ");
        scanf("%d", n);
    }while(*n < 1 || *n > 100);

    for(int i = 0; i < *n; i++)
    {
        printf("Enter element[%d]: ", i);
        scanf("%d", (a + i));
    }
}

//ascending sort
void ascSort(int * a, int n)
{
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

//print function
void printArray(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", *(a + i));
    }
}

//new input and resize
void newInput(int * a, int * n, int *getNewInput)
{
    //user input new value
    printf("\nPlease enter new value: ");
    scanf("%d", getNewInput);
    *n += 1;
    a[*n - 1] = *getNewInput;
}



