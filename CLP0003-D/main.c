#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
const int MAX = 3;
const int maxNumber = 2;

void userPrompt(float * chip);
int userChoice();


//get the chip from the beginning
float getChip(char * fileName);
//The first function of the game
int chipDectector(float chip);
void gameFunction(int * dice, float * chip, int * flag);
void chipCalculator(float * chip, int flag);

//The second function;
void saveFunction(float * chip, char * fileName);

//the third function;
void cashOutPrompt(float * chip);
void cashOutFunction(float * chip);

int main()
{
    //field
    int diceRoll[maxNumber];
    float playerChip;
    char fileName[50] = "chip.txt";
    int flag;
    int choice;

    playerChip = getChip(fileName);
    do
    {
        userPrompt(&playerChip);
        choice = userChoice();
        switch(choice)
        {
            case 1: gameFunction(diceRoll,&playerChip,&flag);
                    chipCalculator(&playerChip,flag);
                    break;
            case 2: saveFunction(&playerChip, fileName);
                    printf("Your chip have been save!\n\n");
                    break;
            case 3: cashOutPrompt(&playerChip);
//                    saveFunction(&playerChip, fileName);
                    cashOutFunction(&playerChip);
                    saveFunction(&playerChip,fileName);
                    break;
        }
    }while(choice == 1);

    return 0;
}

void userPrompt(float * chip)
{
    printf("You have %.2f\n", *chip);
    puts("Choose one of the following menu options:");
    puts("1) Play the slot machine.");
    puts("2) Save game.");
    puts("3) Cash out.");
}

int userChoice()
{
    int getChoice;
    do
    {
        printf("Your choice: ");
        scanf("%d", &getChoice);
    }while(getChoice < 0 || getChoice > MAX);
    return getChoice;
}


float getChip(char * fileName)
{
    char holder[4];
    float convert;
    FILE * userFile;
    userFile = fopen(fileName,"r");

    while(!feof(userFile))
    {
        fgets(holder,5,userFile);
    }
    convert = strtof(holder, NULL);
    fclose(userFile);
    return convert;
}

int chipDectector(float chip)
{
    if((chip - 0.25) >= 0)
    {
        return 1;
    }else
        {
            return 0;
        }
}


void gameFunction(int * dice, float * chip, int * flag)
{
    int checker;
    checker = chipDectector(*chip);
    if(checker == 1)
    {
        printf("The slot machine show: ");
        srand(time(0));
        for(int i = 0; i < 3; i++)
        {
            dice[i] = (rand() % 9) + 1;
            printf("\t%d", dice[i]);
        }


        if(((dice[0] == dice[1]) || (dice[1] == dice[2]) || (dice[2] == dice[0])) && !((dice[0] == dice[1]) && (dice[1] == dice[2])))
        {
            *flag = 1;
            puts("\nYou win 50 cents!");
        }else if((dice[0] == dice[1]) && (dice[1] == dice[2]))
            {
                *flag = 2;
                puts("\nYou win the big prize , $10.00");
            }else
                {
                    *flag = 3;
                    puts("\nSorry you didn't win anything");
                }
        }else if(checker == 0)
            {
                puts("\nYou don't have enough chip to play the game!");
                *flag = 4;
            }
}

void chipCalculator(float * chip, int flag)
{
    if(flag == 1)
    {
        *chip = *chip - 0.25;
        *chip = *chip + 0.50;
    }else if(flag == 2)
        {
            *chip = *chip - 0.25;
            *chip = *chip + 10.00;
        }else if(flag == 3)
        {
            *chip = *chip - 0.25;
            *chip +=0;
        }else if(flag == 4)
            {
                *chip +=0;
            }
}

void saveFunction(float * chip, char * fileName)
{
   char holder[100];
   FILE * userFile;
   userFile = fopen(fileName,"w");
   gcvt(*chip,5,holder);
   fputs(holder,userFile);
   fclose(userFile);
}

void cashOutPrompt(float * chip)
{
    printf("Thanks for playing! You end with %.2f\n\n", *chip);
}

void cashOutFunction(float * chip)
{
    *chip = 10.;
}




