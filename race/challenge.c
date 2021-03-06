#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
Compile with: gcc challenge.c -o challenge -pthread
*/

int VALUE;
int primality;

// Returns true if the number is prime, false otherwise
int is_prime(int number){
    if( number < 2){
        return 0;
    }

    for(int divisor = 2; divisor < number; divisor++){
        if(number % divisor == 0){
            return 0;
        }
    }
    return 1;
}

// Runs the brute force is_prime algorithm
void* pthread_slave(void){
    int new_value = VALUE;

    int primality = is_prime(new_value);

    if(new_value != VALUE){
        // Will have a flag that opens a file, or something along those lines.
        printf("Race!\n" );
    }
}

int main(){

    pthread_t id;
    int ret;
    while(1)
    {
        // Gets the input from the user.
        printf("Give me a value: \n");
        scanf ("%d",&VALUE);

        // opens a new thread
        ret = pthread_create(&id,NULL,&pthread_slave,NULL);

        // Displays the output of the primality to the user.
        if(primality == 0){
            printf("The value %d is not prime...\n",VALUE);
        }else{
            printf("The value %d is prime!\n", VALUE);
        }

    }
    return 0;
}
