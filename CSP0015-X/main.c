#include <stdio.h>
#include <stdlib.h>
const int maxInvitation = 10000;
const double maxPrice = 500;
const int package1 = 50;
const int package2 = 200;

void userPrompt(double * aPrice, double * bPrice, int * card);
int packageChecker(double aPrice, double bPrice, int card);
void buyOnlyA(double aPrice, int card);
void buyOnlyB(double bPrice, int card);
void buyBoth(double aPrice, double bPrice, int card);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void userPrompt(double * aPrice, double * bPrice, int * card)
{
    do{
        puts("What is the price of the small package (in dollars)?");
        scanf("%lf", aPrice);
    }while(*aPrice < 0 || *aPrice > maxPrice);

    do{
        puts("What is the price of the large package (in dollars)?");
        scanf("%lf", b);
    }while(*bPrice < 0 || *bPrice > maxPrice);

    do{
        puts("How many invitation are you sending out?");
        scanf("%d", card);
    }while(*card < 0 || *card > maxInvitation)

}

int packageChecker(double aPrice, double bPrice, int card)
{
    int packageNeeded1 = 0;
    int totalMoney1 = 0;
    int packageNeeded2 = 0;
    int totalMoney2 = 0;

    if(aPrice > bPrice){
        return 1;
    }

    for(int i = package1 ; i <= card; i += package1)
    {
        packageNeeded1++;
        totalMoney1 += aPrice;
    }
    for(int i = package2 ; i <= card; i += package2)
    {
        packageNeeded2++;
        totalMoney2 += aPrice;
    }

    if(card <= package2 && a > b){
        return 1;
    }else if(card <= package2)



}

void buyOnlyB(double b)
{

}
