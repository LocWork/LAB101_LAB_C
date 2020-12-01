#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
int userSum();
void printSum(int sum);
int calculate(int number);
int main()
{
    //variable
    int sum;
    int choice;
   //main code area
    do
    {
        sum = userSum();
        printSum(sum);
        do{
            printf("Press 1 to continue or 0 to stop: ");
            scanf("%d",&choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);
    return 0;
}

int userSum()
{
    int number;
    int sum;
    printf("Enter an integer: ");
    scanf("%d", &number);

    if(number < 0){
        number = number * -1;
    }

    sum = calculate(number);
    return sum;
}

int calculate(int number)
{
   // int qou;
    //int hold = number;
    //int remainder;

    int sum = 0;
    do{
        //qou = number / 10;
        sum += number % 10;
        number = number / 10;
//        sum += remainder;
       // number = qou;
    }while(number != 0);
    return sum;
}

void printSum(int sum)
{
    printf("Sum digit = %d\n", sum);
}
