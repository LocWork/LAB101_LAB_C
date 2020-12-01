#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const int MAX = 100;
void userPrompt(char * a);
void reverseString(char * a);
char changeCases(char letter);
void printString(char * a);

int main()
{
    //variable
    char stringHolder[MAX];
    int choice;
    //main code area
    do
    {   userPrompt(stringHolder);
        reverseString(stringHolder);
        printString(stringHolder);
         do{
            printf("press 1 to continue or 0 to stop: ");
            scanf("%d", &choice);

        }while(choice < 0 || choice > 1);
    }while(choice != 0);
    return 0;
}

void userPrompt(char * a)
{
    printf("Please enter a string: ");
    fflush(stdin);
    gets(a);
}

void reverseString(char * a)
{
    int count = strlen(a);
    int i = 0;
    do{
        char tmp = a[i];
        a[i] = a[count - 1];
        a[count - 1] = tmp;
        i++;
        count--;
    }while(i < count);
}

void printString(char * a)
{
    printf("The reverse of the string: ");
    for(int i = 0; i < strlen(a); i++)
    {
        printf("%c", changeCases(a[i]));
    }
    printf("\n\n");
}

char changeCases(char letter)
{
    char holder = letter;
    if(isupper(holder))
    {

        return tolower(holder);
    }else if(islower(holder))
    {

        return toupper(holder);
    }else{
        return holder;
    }

}
