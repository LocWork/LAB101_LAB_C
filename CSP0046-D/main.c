#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
const int FIBOMAX = 1000;
void firstFunction();
int userChoice();
void secondFunction();
int primesChecker(int number);
void thirdFunction();
int fiboChecker(int number);
void fourthFunction();
int sumOfNumber(int number);


int main()
{

    //field
    int choice;
    char quit;

    //main code
    do
    {
        //prompt and get user choice
        firstFunction();
        choice = userChoice();
        switch(choice)
        {
            case 1: secondFunction();
                    break;
            case 2: thirdFunction();
                    break;
            case 3: fourthFunction();
                    break;
        }

        //continue option
        do
        {
            printf("\nDo you want to continue (Y/N): ");
            fflush(stdin);
            scanf("%c", &quit);
        }while( !(quit == 'y' || quit == toupper('y') || quit == 'n' || quit == toupper('n')));
    }while(!(quit == 'n' || quit == toupper('n')));

    return 0;
}

void firstFunction()
{
    printf("1-The first primes\n");
    printf("2-Fibonacci element\n");
    printf("3-Sum of digits\n");
}

int userChoice()
{
    int getChoice;
    do
    {
        printf("Choose an option: ");
        scanf("%d", &getChoice);
    }while(getChoice < 1 || getChoice >3);
    return getChoice;
}

void secondFunction()
{
    int number;
    int count = 0;
    do
    {
        printf("Number of primes: ");
        scanf("%d", &number);
        if(number < 0)
        {
            puts("A prime number can not be negative!");
        }
    }while(number < 1);

    for(int i = 2; count < number; i++)
    {
        if(primesChecker(i) == 1)
        {
            printf("%d\t", i);
            count++;
        }
    }
}


//    int flag = 0;
//    if(number == 2)
//    {
//        return 1;
//    }else if(number > 2)
//        {
//            for(int index = 1; index < number; index++)
//            {
//                if(number % index == 0)
//                {
//                    flag++;
//                }
//            }
//
//        }
//        if(flag == 1)
//        {
//            return 1;
//        }else
//            {
//                return 0;
//            }
//        flag = 1;
//}

int primesChecker(int number)
{
    int holder;
    int counter = 0;

    if(number == 2)
    {
        return holder = 1;
    }else if(number > 2)
        {
            for(int i = 1; i < number; i++)
            {
                if(number % i == 0)
                {
                    counter++;
                }
            }
        }

    if(counter == 1)
    {
        return holder = 1;
    }else
    {
        return holder = 0;
    }
}

void thirdFunction()
{
    int getChoice;
    int checker = 0;
    do
    {
        printf("Number tested: ");
        scanf("%d", &getChoice);
        if(getChoice < 0)
        {
            puts("A Fibonacci number can not be negative!");
        }
    }while(getChoice < 0);

    checker = fiboChecker(getChoice);
    if(checker == 1)
    {
        puts("It's a Fibonacci term");
    }else
        {
            puts("It's not a Fibonacci term");
        }
    checker = 0;

}

int fiboChecker(int number)
{
    int a = 0;
    int b = 1;
    int total = 0;
    int flag = 0;
    for(int i = 0 ; i < FIBOMAX; i++)
    {
        if(number == total)
        {
            flag = 1;
        }
        total = a + b;
        a = b;
        b = total;
    }

    if(flag == 1)
    {
        return 1;
    }else
        {
            return 0;
        }
    flag = 0;
}

void fourthFunction()
{
    int getChoice;
    int getSum = 0;
    do
    {
        printf("Enter an integer: ");
        scanf("%d", &getChoice);
    }while(getChoice < 0);


    getSum = sumOfNumber(getChoice);
    printf("Sum of it's digits: %d", getSum);

}

int sumOfNumber(int number)
{
    int numberHolder = number;
    int quo;
    int remainder;
    int total = 0;
    do
    {
        quo = number / 10;
        remainder = number % 10;
        number = quo;
        total = total + remainder;
    }while(quo > 0);
    return total;
    total = 0;
}

