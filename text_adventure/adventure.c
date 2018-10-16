#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hacker[200];

int room1(){

    char wanna_cry[] = "I know the competition as a hacker is tough, but does it make you WannaCry?\nWhat was the name of the exploit that led this attack?\nYou will just be eternally blue...\n\n";
    printf(wanna_cry);
    return 1;
}

int room2(){

    char programmer[] = "Why do Java programmers wear glasses?\nThey can't C#! \n\n";
    printf(programmer);
    return 1;
}

int room3(){
    char programmer[] = "How many computer science students does it take to screw in a lightbulb?\nNull, because it's hardware!\n\n";
    printf(programmer);
    return 1;
}

int room4() {
    char programmer[] = "My mom said to me, 'Go get a couple of bottles of milk. If they have eggs, bring six'. I got six bottles of milk.\n\n";
    printf(programmer);
    return 1;
}

int endGame(){


 // %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x
    char attack[] = "\n\nCongrats on finishing the quest... but the reward has been forgotten... Maybe it still lives on the stack.\n ";
    printf("%s", attack);

    char secret[] = "jackie moon!";
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
            contributions[0] = room1();
        }

        else if(room[0] == '2'){
            contributions[1] = room2();
        }
        else if(room[0] == '3'){
            contributions[2] = room3();
        }

        else if(room[0] == '4'){
            contributions[3] = room4();
        }

        if(contributions[0] == 1 && contributions[1] == 1 && contributions[2] == 1 && contributions[3] == 1){
            endGame();
        }
    }
    return 0;
}
