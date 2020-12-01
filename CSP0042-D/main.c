#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
void userInput(int * a, int * number);
void printArray(int * a, int number);
void printMax(int * a, int number);
int getMax(int * a, int number);
void printEvenNumber(int * a, int number);
int getEvenNumber(int checker);

int main()
{
    //field
    int a[MAX];
    int arraySize;
    int choice;

    //main coding area;
    do
    {
        puts("Please input your element(press 0 to stop):");
        userInput(a, &arraySize);
        printArray(a, arraySize);
        printf("\n");
        printMax(a, arraySize);
        printf("\n");
        printf("Array even value:");
        printEvenNumber(a, arraySize);
        printf("\n");
        do
        {
            printf("\nPress 1 to continue or 0 to exit: ");
            scanf("%d", &choice);
            printf("\n");
        }while(choice < 0 || choice > 1);
    }while(choice != 0);

    return 0;
}

void userInput(int * a, int * number)
{
    //khong nen for vi ko biet khi nao nguoi dung nhan 0
    int index;
    int store;

//    printf("Enter the element of the array\n");
//        for(index = 0 ; store != 0; index++)
//        {
//            scanf("%d\n", (a + index));
//            store = *(a+ index);
//        }


    for(index = 0; store != 0 && index < MAX; index++)
    {
        scanf("%d", &a[index]);
        store = a[index];
    }

    *number = index + 1;

    if(index < *number)
    {
        *number = index - 1;
    }

}

void printArray(int * a, int number)
{
    //dung for tai day vi size da co san
    puts("Array elements:");
    for(int i = 0; i < number; i++)
    {
        printf("%d\t", *(a + i));
    }
    printf("\n");
}

void printMax(int * a, int number)
{
    printf("The max value is: %d\n", getMax(a, number));
}


int getMax(int * a, int number)
{
    int maxValue = a[0];
    for(int i = 0; i < number; i++)
    {
        if(maxValue < a[i])
        {
            maxValue = a[i];
        }
    }
    return maxValue;
    //int max = a[0]; // debug
}

void printEvenNumber(int * a, int number)
{
    int flag = 0;
    for(int i = 0; i < number; i++)
    {
        if(getEvenNumber(a[i]) == 1)
        {
            printf("\t%d\t", *(a + i));
            flag = 1;
        }
    }

    if(flag == 0)
    {
        puts("There is no even element!");
    }
}

int getEvenNumber(int checker)
{
    int flag = 0;
    if(checker % 2 == 0)
    {
        return flag = 1;
    }else
    {
        return flag = 0;
    }
    flag = 0;
}


//ko nen dung code nay
//neu ko muon nhan length thi dung code sau
//    do
//    {
//        index = 0;
//        printf("Enter the element of the array\n");
//        do
//        {
//            scanf("%d\n", &a[index]);
//            store = a[index];
//            index = index + 1;
//        }while(store != 0);
//    }while(index < 1 || index > 100);
    //printf("%d\n", index);
//    *number = index - 1;
    //printf("%d\n", *number);
