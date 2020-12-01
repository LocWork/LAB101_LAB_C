#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void userInput(int * n);
void multiTable(int n);


int main()
{
    //field
    int number;
    int choice;

    //main code
    do{
        userInput(&number);
        multiTable(number);
        printf("-------------------------------------\n");
        //continue or exit
        do
        {
            printf("Press enter to 1, 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);

    return 0;
}
//get user input
void userInput(int * n)
{
    do{
        printf("Please enter a number(1-9): ");
        scanf("%d", n);
    }while(*n < 1 || *n > 9);
}
//table void
void multiTable(int n)
{
    int index = 1;
    int total = 1;
    do{
        total = n * index;
        printf("%d x %d = %d\n", n, index, total);
        index++;
    }while(index < 11);
    index = 1;
    total = 1;
}

