/*
This vuln is meant to emulate a time of check vs time of use (TOCTOU) bug, with the file reading.
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/*
Opens and returns the integer value of the TOCTOU.txt file.
*/
char read_from_file(){
    FILE* fp;
    int c;
    fp = fopen("TOCTOU.txt","r");
    while(1){
        c = fgetc(fp);
        if (feof(fp)){
            break;
        }
        return (char)c;
    }
    fclose(fp);
    return 0;
}

/*
Checks to see if the value of the file is 5, then checks if it is 6.
*/
int main(){

    char c = read_from_file();
    printf("%c\n", c);

    // Checks to see if the file has the value 5.
    if (c == '5'){
        sleep(6);
        // Checks to see if the value has a value of 6
        c = read_from_file();
        if(c == '6'){
            printf("Flag\n%s","");
        }else{
            printf("Gone...");
        }
    }
    return 0;
}
