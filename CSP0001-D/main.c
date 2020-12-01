#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 100;
void userString(char * a);
void reverseString(char * a);

int main()
{
    //variable
    char stringHolder[MAX];
    int choice;
    //main code area
    do
    {   userString(stringHolder);
        reverseString(stringHolder);
         do{
            printf("press 1 to continue or 0 to stop: ");
            scanf("%d", &choice);

        }while(choice < 0 || choice > 1);
    }while(choice != 0);
    return 0;
}

void userString(char * a)
{
    printf("Please enter a string: ");
    fflush(stdin);
    gets(a);
}

void reverseString(char * a)
{
    printf("The string reverse: ");
    int count = strlen(a);
    int i;
    for(i = count - 1; i >= 0; i--)
    {
        if(a[i] == ' ' || a[i] == '_')
        {
            a[i] = '\0';
            printf("%s ", &(a[i]) + 1);
        }

    }
    printf("%s\n", a);
}

//        if(a[i] == '_')
//        {
//            a[i] = '_';
//            printf("%s ", &(a[i]) + 1);
//        }
