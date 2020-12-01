#include <stdio.h>
#include <stdlib.h>

void userInput(double * left, int * rate, double * payment);
void printBill(double left, int rate, double payment);
double calculateBill(double * newLeft, double * newRate, double * newPayment);
int canPay(double  left, int  rate, double  payment);
int main()
{
    //variable
    double left;
    int rate;
    double payment;
    int choice;

    //main code area
    do{
        userInput(&left, &rate, &payment);
        printBill(left,rate,payment);
        do
        {
            printf("press 1 to continue or 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);

    }while(choice != 0);
    return 0;
}

void userInput(double * left, int * rate, double * payment)
{
    do{
     do
    {
        puts("What is the value left on the mortgage.");
        scanf("%lf", left);
    }while(*left < 0);
    do{
        puts("What is the annual interest rate of the loan. in percent");
        scanf("%d", rate);
    }while(*rate < 1 || *rate > 12);
    do{
        puts("What is the monthly payment.");
        scanf("%lf", payment);
    }while(*payment < 1);

    }while(canPay(*left,*rate,*payment) == 1);
}



void printBill(double left, int rate, double payment)
{
    double amountOwe;
    double newRate = rate;
    newRate = (newRate / 12) / 100;
    double newLeft = left;
    double newPayment = payment;
    int month = 1;
    printf("Month\tPayment\tAmount Owed");
    do{
        amountOwe = calculateBill(&newLeft, &newRate, &newPayment);
        printf("\n%d\t%.2lf\t%.2lf", month, newPayment, amountOwe);
        month++;
    }while(amountOwe != 0);
    printf("\n");
}

double calculateBill(double * newLeft, double * newRate, double * newPayment)
{
    double amount;
    double checker;

    checker = ( *newLeft + (*newLeft * (*newRate)) );
    if(checker > *newPayment){
        amount = ( *newLeft + (*newLeft * (*newRate) ) - *newPayment);
    }else
    {
        *newPayment = checker;
        amount = checker - *newPayment;
    }
    *newLeft = amount;

    return amount;
}

int canPay(double left , int rate, double payment)
{
    double newRate = rate;
    newRate = (newRate / 12) / 100;
    double checker;
    double amount;

    checker = (left * newRate);
    amount = (left + (left * newRate)) - payment;
    if(payment < checker){
        return 1;
    }else{
        return 0;
    }

}
