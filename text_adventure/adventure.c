#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void error(char *msg)
{
    perror(msg);
    exit(1);
}

char hacker[200];

char *room1(void ){

    static char* wanna_cry = "I know the competition as a hacker is tough, but does it make you WannaCry?\nWhat was the name of the exploit that led this attack?\nYou will just be eternally blue...\n\n";
    return wanna_cry;
}

char *room2(){

    static char* programmer = "Why do Java programmers wear glasses?\nThey can't C#! \n\n";
    return programmer;
}

char *room3(){
    static char* programmer = "How many computer science students does it take to screw in a lightbulb?\nNull, because it's hardware!\n\n";
    return programmer;
}

char *room4() {
    static char* programmer = "My mom said to me, 'Go get a couple of bottles of milk. If they have eggs, bring six'. I got six bottles of milk.\n\n";
    return programmer;
}

int endGame(){

    char attack[] = "\n\nCongrats on finishing the quest... but the reward has been forgotten... Maybe it still lives on the stack.\n ";
    printf("%s", attack);

    FILE *flag;
    flag = fopen("./flag.txt","r");

    char* flags;
    fscanf(flag, "%s",flags);

    printf(strcat(hacker,",you have fought very bravily, but I am sorry...Hack the planet!\n"));

    exit(0);
}

void intro(){

    char alias[] = "Let the bad puns begin...\nWhat is your hacker alias?\n" ;
    printf("%s",alias);

    fgets(hacker,200,stdin);
    hacker[strcspn(hacker, "\n")] = 0;

}

int main() {
    intro();

    int contributions[4] = {0,0,0,0};

    while(1){
        char room[20];
        printf("Which room would you like to visit? 1-4 are options\n");

        fgets(room, 20, stdin);

        if(room[0] == '1'){
            contributions[0] = 1;
            printf(room1());
        }

        else if(room[0] == '2'){
            contributions[1] = 1;
            printf(room2());
        }
        else if(room[0] == '3'){
            contributions[2] = 1;
            printf(room3());
        }

        else if(room[0] == '4'){
            contributions[3] = 1;
            printf(room4());
        }

        if(contributions[0] == 1 && contributions[1] == 1 && contributions[2] == 1 && contributions[3] == 1){
            endGame();
        }
    }
    return 0;
}

