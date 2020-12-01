#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void userPrompt();
const double PI = 3.14;
const double ITM = 63.360;
int userChoice();
//first function
void printMPG(double speed, double gas, double time);
double getMPG(double speed, double gas, double time);
//second function
void printMPR(double rad, double rel);
double getMPR(double rad, double rel);
//third function
void printRMPG(double rad, double rel,double gas);
double getRMPG(double rad, double rel,double gas);


//v2
double timeInput(int * time);
double speedInput(int * speed);
void gasInput(double * gas);
void radiusInput(double * rad);
double relvolutionInput(int * rel);

int main()
{
    //variable
    int choice;
    int time;
    double timeInHour;

    int speed;
    double newSpeed;

    double radius;

    int rel;
    double newRel;

    double gas;
    //main code area
    do{
        userPrompt();
        choice = userChoice();
        switch(choice)
        {
            case 1:
                timeInHour = timeInput(&time);
                newSpeed = speedInput(&speed);
                gasInput(&gas);
                printMPG(newSpeed,gas,timeInHour);
                break;
            case 2:
                radiusInput(&radius);
                newRel = relvolutionInput(&rel);
                printMPR(radius, newRel);
                break;
            case 3:
                radiusInput(&radius);
                newRel = relvolutionInput(&rel);
                gasInput(&gas);
                printRMPG(radius, newRel,gas);
                break;
        }
    }while(choice != 4);

    //debug area;
//   calculateFuelEconomy();
//     calculatingDistanceTraveled();
    return 0;
}

void userPrompt()
{
    puts("1-Calculating Fuel Economy");
    puts("2-Calculating Distance Traveled");
    puts("3-Revised Fuel Economy Calculation");
    puts("4-Quit");
}

int userChoice()
{
    int getChoice;
    do{
        printf("Your choice: ");
        scanf("%d", &getChoice);
    }while(getChoice < 1 || getChoice > 4);
    return getChoice;
}
double timeInput(int * time)
{
    do{
        puts("How many minutes did you travels?");
        scanf("%d", time);
    }while(*time < 0);
    return *time;
}
double speedInput(int * speed)
{
    do{
        puts("What was the average speed of the car during that time?");
        scanf("%d", speed);
    }while(*speed < 0);
    return *speed;
}
void gasInput(double * gas)
{
    do{
        puts("How many gallons of gas did your car use?");
        scanf("%lf", gas);
    }while(*gas < 0);
}
void radiusInput(double * rad)
{
    do{
        puts("What is the radius of the tire? (in inches)");
        scanf("%lf", rad);
    }while(*rad < 0);
}
double relvolutionInput(int * rel)
{
    do{
        puts("How many revolution did your car's tires make?");
        scanf("%d",rel);
    }while(*rel < 0);
    return *rel;
}

void printMPG(double speed , double  gas, double time)
{
    double answer = getMPG(speed , gas,time);
    printf("Your car travel %.2lf miles per gallons\n\n", answer);

}

double getMPG(double speed , double  gas, double time)
{
    double answer;
    time = time / 60;
    answer = (speed * time) / gas;
    return answer;
}


void printMPR(double rad, double rel)
{
    double answer = getMPR(rad,rel);
    printf("Your car travel %.2lf miles\n\n", answer);
}

double getMPR(double rad, double rel)
{
    double milePerRel;
    double answer;
    rel = rel / 1000;
    milePerRel = rad * 2 * PI / ITM;
    answer = milePerRel * rel;
    return answer;
}

void printRMPG(double rad, double rel , double gas)
{

    double answer = getRMPG(rad,rel ,gas);

    printf("Your car travel %.2lf miles\n\n", answer);
}

double getRMPG(double rad, double rel , double gas)
{
    double milePerRel;
    double distance;
    double answer;

    //doi tu inches sang mile the revoulution chia 1000
    rel = rel / 1000;

    milePerRel = rad * 2 * PI / ITM;
    distance = milePerRel * rel;
    answer = distance / gas;
    return answer;
}


