#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


char read_from_file(){
    FILE* fp;
    int c;
    fp = fopen("value","r");
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

int main(){

    char c = read_from_file();
    printf("%c\n", c);
    if (c == '5'){
        sleep(6);
        c = read_from_file();
        if(c == '6'){
            printf("Flag\n%s","");
        }else{
            printf("Gone...");
        }
    }
    return 0;
}
