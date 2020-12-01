#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int holder = 3;

void userPrompt();
int userChoice();
void quadraticFunction(float * a, float * b, float * c);
float deltaCalculation(float a, float b, float c);
float specialQuadratic(float a, float b);
float normalQuadraticOne(float a, float b, float c, float delta);
float normalQuadraticTwo(float a, float b, float c, float delta);
void bankFunction(float * deposit, float * rate, float * months);
float bankSolution(float deposit, float rate, float months);
//co the tach ham;

int main()
{
    //field
    int choice;
    float a, b, c;
    float deposit, rate, months; //luu de xem cach pointer hoat dong

    //main code area
    do
    {
        userPrompt();
        choice = userChoice();
        //return area
        switch(choice)
        {
            case 1: quadraticFunction(&a, &b, &c);
                    break;
            case 2: bankFunction(&deposit, &rate, &months); //&deposit, &rate, &months
                    break;

        }
    }while(choice != holder);
    return 0;
}

void userPrompt()
{
    puts("MENU");
    puts("-------------------------------");
    puts("1- Quadratic equation");
    puts("2- Bank deposit problem");
    puts("3- Quit");
}

int userChoice()
{
    int choice;
    do
    {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
    }while(choice < 1 || choice > holder);

    return choice;
}

void quadraticFunction(float * a, float * b, float * c)
{
    float delta;
    float x1, x2, xSpecial;
    puts("Please enter the value of : ax^2 + bx + c");
    do
    {
        printf("a = ");
        scanf("%f", a);
        if(*a == 0)
        {
            puts("A cannot be zero!");
        }
    }while(*a == 0);

    printf("b = ");
    scanf("%f", b);

    printf("c = ");
    scanf("%f", c);

    delta = deltaCalculation(*a, *b, *c);
    printf("Delta = %.2f\n", delta);
    if(delta < 0)
    {
        puts("The equation has no solution!");
    }else if(delta == 0)
        {
            xSpecial = specialQuadratic(*a, *b);
            printf("x1 = x2 = %.2f\n", xSpecial);
        }else if(delta > 0)
            {
                x1 = normalQuadraticOne(*a, *b, *c, delta);
                x2 = normalQuadraticTwo(*a, *b, *c, delta);
                printf("x1 = %.2f\n", x1);
                printf("x2 = %.2f\n", x2);
            }

}

float deltaCalculation(float a, float b, float c)
{
    float delta = 1;
    delta = pow(b,2) - (4 * a * c);
    return delta;
}

float specialQuadratic(float a, float b)
{
    float specialCondition = 1;
    specialCondition = -(b / (2 * a));
    return specialCondition;
}


float normalQuadraticOne(float a, float b, float c, float delta)
{
    float x1 = 1;
    x1 = (-b - sqrt(delta)) / (2 * a);
    return x1;
}
float normalQuadraticTwo(float a, float b, float c, float delta)
{
    float x2 = 1;
    x2 = (-b + sqrt(delta)) / (2 * a);
    return x2;
}
void bankFunction(float * deposit, float * rate, float * months)
{
    float total;
    puts("Please enter the following");
    do
    {
        printf("Deposit = ");
        scanf("%f", deposit);
    }while(*deposit < 0);

    do
    {
        printf("Interest rate = ");
        scanf("%f", rate);
        if(*rate > 0.100001)
        {
            printf("The rate must be 0.1 or lower!\n");
        }
    }while(*rate > 0.100001);
 //   printf("%d", rate); debug

    do
    {
        printf("Number of deposit months = ");
        scanf("%f", months);
    }while(*months < 1 || *months > 12);

//    total =  deposit * rate * months;
    total = bankSolution(*deposit, *rate, *months);
    printf("The Total amount received: %.2f\n", total);

}

float bankSolution(float deposit, float rate, float months)
{
    float answer = 1;
    answer = deposit * rate * months;
    return answer;
}





