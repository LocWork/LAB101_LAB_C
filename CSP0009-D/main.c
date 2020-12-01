#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
void userInput(int * a, int * n);
int minFinder(int * a, int n);
int positionFinder(int * a, int n);

int main()
{
    //field
    int arraySize;
    int a[MAX];
    int choice;

    //main section
    do
    {
        userInput(a, &arraySize);
        printf("The smallest number is %d and founded at the %d position", minFinder(a, arraySize), positionFinder(a, arraySize));
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
    //new field
    int userNumber;
    int numberposition;

    //enter size and array
    do
    {
        printf("Please enter size of array: ");
        scanf("%d", n);
    }while(*n < 1 || *n > MAX);

    for(int i = 0; i < *n; i++)
    {
        printf("Element[%d] = ", i);
        scanf("%d", (a + i));
    }

}

int minFinder(int * a, int n)
{
    //firld
    int minimum = a[0];
    for(int i = 0; i < n; i++)
    {
        if(minimum > a[i])
        {
            minimum = a[i];
        }
    }
    return minimum;
}

int positionFinder(int * a, int n)
{
    int mini = a[0];
    int holder = 1;
    for(int i = 0; i < n; i++)
    {
        if(mini > a[i])
        {
            holder = i;
        }
    }
    return holder;
}




