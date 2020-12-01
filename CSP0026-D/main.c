#include <stdio.h>
#include <stdlib.h>
int userNumber();
void answer(int n);
int main()
{
    //field
    int number;
    char press;
    int choice;

    //main code area
    do{
        puts("Convert Decimal to Binary program");
        number = userNumber();
        answer(number);
        do
        {
            printf("\nPress 1 to continue, 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);
    return 0;
}

int userNumber()
{
    int n;
    int qou , remainder;
    do
    {
        printf("Enter a positive number: ");
        scanf("%d", &n);
    }while(n < 1);
}

void answer(int n)
{
    int quo, remainder, aSize;
    int a[100];
    int flag = 0;


    do{
       quo = n / 2;
       remainder = n % 2;
       a[flag] = remainder;
//     printf("%d", a[flag]); //edit code here
       flag++;
       n = quo;
    }while(quo != 0);
//  flag -=1;                 //edit code here
    printf("Binary number: ");


//    do{                               //debug
////            printf("%d\n",flag);
//        printf("%d", a[flag]);
//        flag--;
//    }while(flag >= 0);

    for(int i = flag - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
}
