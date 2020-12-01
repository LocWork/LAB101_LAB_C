#include <stdio.h>
#include <stdlib.h>
const int MIN = 1900;
const int MAX = 9999;
const int maxChoice = 3;
void userPrompt();
int userChoice();

void dateInput();
int dateProcessing(int checkDate, int checkMonth, int checkYear);
void charaterPrint();
void swap(char * a,char * b);


int main()
{
    //field
    int choice;

    //main code area
    do
    {
        userPrompt();
        choice = userChoice();
        switch(choice)
        {
            case 1: dateInput();
                    break;
            case 2: charaterPrint();
                    break;
        }
    }while(choice != 3);


//  debug area
//    do
//    {
//        dateInput();
//    }while(1 == 1);

//    charaterPrint();
    return 0;
}

void userPrompt()
{
    puts("MENU");
    puts("1- Processing date data");
    puts("2- Character data");
    puts("3- Quit");
}

int userChoice()
{
    int getChoice;
    do
    {
        printf("Enter Your Choice: ");
        scanf("%d", &getChoice);
    }while(getChoice < 1 || getChoice > 3);

    return getChoice;
}

void dateInput()
{
    int getDate, getMonth, getYear;
    printf("Your date: ");
    scanf("%d %d %d", &getDate, &getMonth, &getYear);

    if(dateProcessing(getDate, getMonth, getYear) == 1)
    {
        puts("This is a valid date");
    }else
        {
            puts("This is not a valid date");
        }

    printf("\n");

}


int dateProcessing(int checkDate, int checkMonth, int checkYear)
{
    int flag = 1;
    if(checkMonth < 1 || checkMonth > 12 || checkYear < MIN || checkYear > MAX)
    {
        return flag = 0;
    }

    if(checkMonth == 1 || checkMonth ==  3 || checkMonth == 5 || checkMonth == 7 || checkMonth == 8 || checkMonth == 10 || checkMonth == 12)
    {
        if(checkDate < 1 || checkDate > 31)
        {
            return flag = 0;
        }
    }else if((checkMonth != 2) && (checkMonth == 4 || checkMonth ==  6 || checkMonth == 9 || checkMonth == 11))
        {
            if(checkDate < 1 || checkDate > 30)
            {
                return flag = 0;
            }
        }else if(checkMonth == 2)
            {
                if((checkYear % 400 == 0) || (checkYear % 4 == 0 && checkYear % 100 != 0))
                {
                    if(checkDate < 1 || checkDate > 29)
                    {
                        return flag = 0;
                    }
                }else
                {
                    if(checkDate < 1 || checkDate > 28)
                    {
                        return flag = 0;
                    }
                }
            }

    return flag;
}



void charaterPrint()
{
    char a, b;

    printf("Please Enter two Character: ");
    fflush(stdin);
    scanf("%c %c", &a, &b);

    if(a < b)
    {
        char tmp = a;
        a = b;
        b = tmp;
    }
    for(char i = a ; i >= b; i--)
    {
        printf("%c: %d\n", i, i);
    }
    printf("\n");
}






