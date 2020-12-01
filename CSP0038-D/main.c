#include <stdio.h>
#include <stdlib.h>
const int MAX = 1000;
int userPrompt(char * getName);
void readFile(char * getName);

int main()
{
    //fields
    char fileName[50];
    int choice;
    int getPrompt;
    do
    {
        getPrompt = userPrompt(fileName);
        if(getPrompt == 1)
        {
            readFile(fileName);
        }
        do
        {
            printf("Press 1 to continue or 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);
    return 0;
}

int userPrompt(char * getName)
{
    printf("File name: ");
    fflush(stdin);
    gets(getName);
    FILE * userFile;
    if((userFile = fopen(getName, "r")) == NULL)
    {
        puts("That file does not exit");
        return 0;
    }
    return 1;
}

void readFile(char * getName)
{
    char buffer[MAX];
    puts("File content:");
    FILE * userFile;
    userFile = fopen(getName, "r");

    fseek(userFile,0, SEEK_SET);
    while(!feof(userFile))
    {
        fgets(buffer, MAX, userFile);
        puts(buffer);
    }
    fclose(userFile);
}
