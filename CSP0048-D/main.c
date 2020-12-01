#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 10;
const int getMAX = 1000;
void userInput(char * getName);
void writeContent(char * getName, char * content);
void readContent(char  * getName, char * content);

int main()
{
    //fields
    char fileName[50];
    char stringHolder[MAX];
    int choice;

    //main code area
    do
    {
        userInput(fileName);
        writeContent(fileName, stringHolder);
        readContent(fileName, stringHolder);
        printf("\n");
        do
        {
            printf("Press 1 to continue or 0 to exit: ");
            scanf("%d", &choice);
        }while(choice < 0 || choice > 1);
    }while(choice != 0);

    return 0;
}

void userInput(char * getName)
{
        printf("Enter file name to save content: ");
        fflush(stdin);
        gets(getName);
}

void writeContent(char * getName, char * content)
{
//      char getContent[1000];

//      get user content here
    printf("Enter content: ");
    fflush(stdin);
    gets(content);

    FILE * userFile;
//    if(userFile == NULL)
//    {
//        userFile = fopen(getName, "w");
//        fwrite(content,sizeof(char),strlen(content),userFile);
//    }else if(userFile != NULL){

        userFile = fopen(getName, "a");
 //       fwrite(content,sizeof(char),strlen(content),userFile);
        fputs(content,userFile);
//    }

    fclose(userFile);
}

void readContent(char * getName, char * content)
{
    char buffer[getMAX];
    puts("\nFile content: ");
    FILE * userFile;
    userFile = fopen(getName, "r");

    fseek(userFile,0, SEEK_SET);

//   fread(buffer,sizeof(char),getMAX,userFile);
    while(!feof(userFile))
    {
        fgets(buffer,getMAX,userFile);
        puts(buffer);
    }

    fclose(userFile);
}
