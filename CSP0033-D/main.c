#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
int userCount();
//int userSum(int * a,int len);
int userSum(int len);
int calculate(int * a, int len);
void printAnswer(int sum);

int main()
{
    //variable
//    int * a; // dung dung point tai day
    int count, sum = 0;
    int choice;


    //main code area
    do
    {
        count = userCount();
//        sum = userSum(a, count);
        sum = userSum(count);
        printAnswer(sum);
        do{
            printf("Press 1 to continue or 0 to stop: ");
            scanf("%d",&choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);

    return 0;
}

int userCount()
{
    int number;
    do
    {
        printf("Number of element n = ");
        scanf("%d", &number);
    }while(number < 0 || number > MAX);
    return number;
}

int userSum(int len)
{
    int sum = 0;
    int * a;
    a = (int*) malloc(len * sizeof(int));
    for(int i = 0; i < len; i++)
    {
        printf("\tEnter an interger: ");
        scanf("%d", &a[i]);
    }

    sum = calculate(a, len);
    free(a);
    return sum;
}

int calculate(int * a, int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum += a[i];
    }
    return sum;
}

void printAnswer(int sum)
{
    printf("\tSum = %d\n\n", sum);
}
