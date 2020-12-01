#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const int MAX = 100;
void userString(char * a);
int stringChecker(char * a);
int numberChecker(char * a, char b);
void rePrintString(char * a);

int main()
{
    //variable
    char stringHolder[MAX];
    int choice;

    //main code area
    do
    {   userString(stringHolder);
        rePrintString(stringHolder);
         do{
            printf("press 1 to continue or 0 to stop: ");
            scanf("%d", &choice);

        }while(choice < 0 || choice > 1);
    }while(choice != 0);
    return 0;
}

void userString(char * a)
{
    do{
        printf("Please enter a string: ");
        fflush(stdin);
        gets(a);
    }while(stringChecker(a) == 0);
}


int stringChecker(char * a)
{
    int count = strlen(a);
    for(int i = 0; i < count; i++)
    {
        if(isalpha(a[i]) == 0 && a[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

void rePrintString(char * a)
{
    printf("Found character: ");
    int count = strlen(a);
    for(int i = 0; i < count; i++)
    {
        if(numberChecker(a, a[i]) == 1)
        {
            printf("%c\t", a[i]);
        }
    }
    printf("\n\n");
}

int numberChecker(char * a, char b)
{
    int count = strlen(a);
    int flag = 0;
    for(int i = 0; i < count; i++)
    {
        if(a[i] == b)
        {
            flag++;
            if(flag > 1)
            {
                return 0;
            }
        }
    }

    return 1;

}

