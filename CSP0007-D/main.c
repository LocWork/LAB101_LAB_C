#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ascii table sheet 48 --> 57 56-- > 90 97 --> 122
const int MAX = 100;
void userString(char * a);
int stringChecker(char * a);
void blankRemover(char * a);
void printString(char * a);

int main()
{
    //variable
    char stringHolder[MAX];
    int choice;
    do{
        userString(stringHolder);
        blankRemover(stringHolder);
        printString(stringHolder);
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

//ascii table sheet 48 --> 57 65-- > 90 97 --> 122
int stringChecker(char * a)
{

    // use isalpha is much better
    int count = strlen(a);
    for(int i = 0; i < count; i++){
        if(a[i] > 32 && (a[i] < 48 || a[i] > 57) && (a[i] < 65 || a[i] > 90) && (a[i] < 97 || a[i] > 122) ){
            return 0;
        }
    }

//    for(int i = 0; i < count; i++)
//    {
//        if(isalpha(a[i]) == 0 && a[i] != ' ')
//        {
//            return 0;
//        }
//    }
    return 1;


}

void blankRemover(char * a)
{
    int count = strlen(a);
    for(int i = 0; i < count; i++){
        if(a[i] == ' ' && a[i + 1] == ' '){
            for(int j = i; j < count ; j++){
                a[j] = a[j + 1];
            }
            i--;
            count--;
        }
    }
}

void printString(char * a)
{
    printf("The string after removing: %s\n\n", a);
}
