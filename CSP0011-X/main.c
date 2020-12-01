#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
const int MAX = 100;
const int maxChoice = 4;

void userPrompt();
int userChoice();

//binary
void userInput(char * number, int * flag, int choice);
//octal
//void octalInput(char * number, int * flag);
////hexadecimal
//void hexaInput(char * number, int * flag);


//re-use function for binary and
void printDecimal(int flag, char * character);
int detector(int flag ,char * character);
int converter(int flag, char * character);

int main()
{
    //field
    int typeChecker;
    char typeNumber[MAX];
    int choice;

    //main code area
    do
    {
        userPrompt();
        choice = userChoice();
        switch(choice)
        {
            case 1: userInput(typeNumber, &typeChecker,choice);
                    printDecimal(typeChecker, typeNumber);
                    printf("\n");
                    break;
            case 2: userInput(typeNumber, &typeChecker,choice);
                    printDecimal(typeChecker, typeNumber);
                    printf("\n");
                    break;
            case 3: userInput(typeNumber, &typeChecker,choice);
                    printDecimal(typeChecker, typeNumber);
                    printf("\n");
                    break;
        }
    }while(choice != 4);



//  debug area
//    binaryInput(&typeNumber, &typeChecker);
//    octalInput(&typeNumber, &typeChecker);
//        hexaInput(typeNumberHexa, &typeChecker);
//    printDecimal(typeNumber, typeChecker, typeNumberHexa);

    return 0;
}

void userPrompt()
{
    puts("MENU");
    puts("----------------------------------------------------------");
    puts("1-Convert binary number to decimal number");
    puts("2-Convert octal number to decimal number");
    puts("3-Convert hexadecimal number to decimal number");
    puts("4-Exit");
}

int userChoice()
{
    int getChoice;
    do
    {
        printf("Please choose number(1-4): ");
        scanf("%d", &getChoice);
    }while(getChoice < 1 || getChoice > maxChoice);
    return getChoice;
}

void userInput(char * number, int * flag, int choice)
{
    int checker;
    if(choice == 1)
    {
        *flag = 1;
    }else if(choice == 2)
    {
        *flag = 2;
    }else if(choice == 3)
    {
        *flag = 3;
    }
    do
    {
            if(*flag == 1)
            {
                printf("Enter binary number: ");
            }else if(*flag == 2)
                {
                    printf("Enter an octal number: ");
                }else if(*flag == 3)
                    {
                        printf("Enter a hexadecimal number: ");
                    }
            fflush(stdin);
            gets(number);
        checker = detector(*flag, number);
    }while(checker == 0);
}

int detector(int flag, char * character)
{
//    int quo, remainder;
//    int holder = number;
    int minSize1, minSize2, maxSize1, maxSize2;
//    printf("%d\n", flag);
    if(flag == 1)
    {
        minSize1 = 48;
        maxSize1 = 49;
    }

    if(flag == 2)
    {
        minSize1 = 48;
        maxSize1 = 56;
    }
    if(flag == 3)
    {
        minSize1 = 48;
        maxSize1 = 57;

        minSize2 = 61;
        maxSize2 = 70;
    }
    if(flag == 1 || flag == 2)
    {
        for(int i = 0; i < strlen(character); i++)
        {
            if((character[i] < minSize1 || character[i] > maxSize1))
            {
                return 0;
            }
        }
    }else if (flag == 3)
        {
            for(int i = 0; i < strlen(character); i++)
            {

                if((character[i] < minSize1 || character[i] > maxSize1) && (character[i] < minSize2 || character[i] > maxSize2))
                {
                    return 0;
                }
            }

        }

    return 1;
}

void printDecimal(int flag, char * number)
{
     printf("Decimal number is: %d", converter(flag, number));
}

int converter(int flag, char * character)
{
    int index = 0;
    int decimalNumber = 0;
    int convertionNumber;
    int charConverter;

    if(flag == 1)
    {
        convertionNumber = 2;
    }

    if(flag == 2)
    {
        convertionNumber = 8;
    }
    if(flag == 3)
    {
        convertionNumber = 16;
    }

    //get the size of the binary number
            index = strlen(character) - 1;
            for(int i = 0; i < strlen(character); i++)
            {
                charConverter = character[i] - '0';
                if(flag == 3)
                {
                    if(charConverter > 9 )
                    {
                        charConverter -= 7;
                    }
                }
                decimalNumber += charConverter * pow(convertionNumber, index);
                index--;
            }
            index = 0;
    return decimalNumber;
}
