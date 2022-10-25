#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char** input_line(){
    char* inp= NULL;
    size_t size=0;
    getline(&inp,&size,stdin);
    int inp_length=10;
    char **words= malloc(inp_length*sizeof(char*));
    char *word = strtok(inp, "\n\t\r ");
    int i=0;
    while(word!=NULL){
        words[i]=word;
        if(++i>=inp_length){
            inp_length++;
            words=realloc(words,inp_length*sizeof(char*));
        }
        word = strtok(NULL,"\n\t\r ");
    }
    words[i]=NULL;
    return words;
}


int main(){
    while(1){
        char **input=input_line();
        for(int i=0;i<sizeof(input);i++){
            printf("%s\n",*(input+i));
        }
    }
    return 0;
}


