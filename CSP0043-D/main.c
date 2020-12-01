#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//const for the maximum option and the size of the array
const int MAX = 100;

//gioi han choice cua nguoi dung giup thay doi code de hon
const int choiceMax = 8;

//Cac function cua bai
void userPrompt();
int userChoice();

//Insert function dung de debug and defaunt neu flag == 0
void inputArray(int * a, int * number, int * flag);

//7 cai function trong bai
void addNumber(int * a, int * number, int * flag);
void searchNumber(int * a, int * number, int * flag);
//int searchDetector(int * a, int n); du thua
void removeFirstNumber(int * a, int * number, int * flag);
void removeAllNumber(int * a,int * number, int * flag);
void printArray(int * a, int number, int * flag);
void ascSort(int * a, int * number, int * flag);
void descSort(int * a,int * number, int * flag);

int main()
{
    //field
    int a[MAX];
    int getChoice;
    int arraySize = 0;
    int activeFlag; //dung nen hard code activeFlag = 0 tai ban dau

    //main code area
    do
    {
        userPrompt();
        getChoice = userChoice();
        switch(getChoice)
        {
            case 1: addNumber(a, &arraySize, &activeFlag);
                    break;
            case 2: searchNumber(a, &arraySize, &activeFlag);
                    break;
            case 3: removeFirstNumber(a, &arraySize, &activeFlag);
                    break;
            case 4: removeAllNumber(a, &arraySize, &activeFlag);
                    break;
            case 5: printArray(a, arraySize, &activeFlag);
                    break;
            case 6: ascSort(a, &arraySize, &activeFlag);
                    break;
            case 7: descSort(a, &arraySize, &activeFlag);
                    break;
        }
    }while(getChoice != 8);


//    test and debug area
//    inputArray(a, &arraySize, &activeFlag);
//    removeFirstNumber(a, &arraySize, &activeFlag);
//    removeAllNumber(a, &arraySize, &activeFlag);
//    addNumber(a, &arraySize, &activeFlag);
//    searchNumber(a, &arraySize, &activeFlag);
//    ascSort(a, &arraySize, &activeFlag);
//    descSort(a, &arraySize, &activeFlag);
//    printArray(a, arraySize, &activeFlag);
//    printf("\n%d", activeFlag);
//    removeAllNumber(a, &arraySize, &activeFlag);
//    for(int i = 0 ; i < 4; i++)
//    {
//        printf("\t%d", a[i]);
//    }
//    printf("%d", arraySize);
//        printf("\n%d", activeFlag);
//        printf("%d", arraySize);

    return 0;
}

//print menu
void userPrompt()
{
    puts("MENU");
    puts("------------------------------");
    puts("1-Add a value");
    puts("2-Search a value");
    puts("3-Remove the first existence of a value");
    puts("4-Remove all existences of a value");
    puts("5-Print out the array");
    puts("6-Sort the array in ascending order");
    puts("7-Sort the array in descending order");
    puts("8-Quit!");
}

int userChoice()
{
    int choice;
    do
    {
        printf("Your choice: ");
        scanf("%d", &choice);
    }while(choice < 1 || choice > choiceMax);
    return choice;
}


//default neu flag = 0; Ham nay co the duoc thay the boi ham addNumber
void inputArray(int * a, int * number,int * flag)
{
    printf("\n");
    puts("Hey there is currently no element!");
    puts("So please enter the following:");
    do
    {
        printf("Please enter the size of the array: ");
        scanf("%d", number);
    }while(*number < 1 || *number > MAX);

    for(int i = 0; i < *number; i++)
    {
        printf("Enter the [%d] element: ", i + 1);
        scanf("%d", &a[i]);
    }

    *flag = 1;


}

void addNumber(int * a, int * number, int *  flag)
{
//    index holder de debug truong hop sai
//    int indexHolder;
    int userNumber;


    if(*number > 100)
    {
        printf("The array is full!\n");
        *flag = 1;
    }else
    {
        *number += 1;
        printf("Enter your number: ");
        scanf("%d", &userNumber);
        a[*number - 1] = userNumber;
        puts("A new number has been added to your array!");
        printf("\n");
        *flag = 1;
    }
}

void searchNumber(int * a, int * number, int * flag)
{
    int userNumber;
    int counter = 0;
    if(*flag != 1)
    {
        inputArray(a, number, flag);
    }

    printf("Enter a number: ");
    scanf("%d", &userNumber);

    for(int i = 0; i < *number; i++)
    {
        if(a[i] == userNumber)
        {
            printf("The number %d have/has been found at the %d position\n", userNumber, i + 1);
            counter = 1;
        }
    }

    if(counter != 1)
    {
        puts("Your number does not exits!");
    }
    printf("\n");
}

void removeFirstNumber(int * a, int * number, int * flag)
{
    //field
    int userNumber;
    int counter = 0;
    if(*flag != 1)
    {
        inputArray(a, number, flag);
    }

    printf("Please enter a number: ");
    scanf("%d", &userNumber);

    for(int i = 0; i < *number; i++)
    {
        if(a[i] == userNumber && counter == 0)
        {
            for(int j = i; j < *number; j++)
            {
                a[j] = a[j + 1];
            }
            counter++;
            *number = *number - 1;
        }
    }

    if(*number < 1)
    {
        *flag = 0;
    }

    if(counter != 0)
    {
        puts("The number has been deleted");
    }else{
        puts("That number does not exit");
    }

    counter = 0;

}

void removeAllNumber(int * a, int * number, int * flag)
{
    int userNumber;
    int counter = 0;
    if(*flag != 1)
    {
        inputArray(a, number, flag);
    }

        printf("Please enter a number: ");
        scanf("%d", &userNumber);

        for(int i = 0; i < *number; i++)
        {
            if(a[i] == userNumber)
            {
                for(int j = i; j < *number; j++)
                {
                    a[j] = a[j + 1];

                }
                i--;
                *number = *number - 1;
                counter = 1;
            }
        }

        if(*number < 1)
        {
            *flag = 0;
        }

        if(counter == 1)
        {
            puts("The value has been deleted!");
        }else{
            puts("The value does not exits!");
        }
    printf("\n\n");
}

void printArray(int * a, int  number, int * flag)
{
    if(*flag != 1)
    {
        inputArray(a, &number, flag);
    }
    printf("Your array: ");
    for(int i = 0; i < number; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n\n");
}

void ascSort(int * a, int * number, int * flag)
{
    if(*flag != 1)
    {
        inputArray(a, number, flag);
    }

    for(int i = 0; i < *number - 1; i++)
    {
        for(int j = *number - 2; j >= i; j--)
        {
            if(a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    printf("Your array has been sorted\n");
    printf("\n");
}

void descSort(int * a, int * number, int * flag)
{
    if(*flag != 1)
    {
        inputArray(a, number, flag);
    }

    for(int i = 0; i < *number - 1; i++)
    {
        for(int j = *number - 2; j >= i; j--)
        {
            if(a[j] < a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    printf("Your array has been sorted\n");
    printf("\n");
}
