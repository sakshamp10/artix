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
    char *word = strtok(inp, " ");
    int i=0;
    while(word!=NULL){
        words[i]=word;
        if(++i>=inp_length){
            inp_length+=10;
            words=realloc(words,inp_length*sizeof(char*));
        }
        word = strtok(NULL," ");
    }
    words[i]=NULL;
    return words;
}

void echo(char** input){

    //left for later

    for(int i=1;input[i]!=NULL;i++){
        for(int j=0;input[i][j]!='\0';j++){
            if(input[i][j]!='\\')
                printf("%c",input[i][j]);
            else{
                if(input[i][j]=='\\'){
                }
            }
        }
        printf(" ");
    }
}

void pwd(){
    size_t size=0;
    char *pwd=NULL;
    pwd=getcwd(pwd,size);
    char p=0;
    while(pwd[p]!='\0'){
        printf("%c",p);
        p++;
    }
}

void free2D(char** input){
    int i=0;
    while(input[i]!=NULL){
        free(input[i]);
        i++;
    }
    free(input);
}

char* delim(char* input){
    input=strtok(input,"\n");
    return input;
}

int main(){
    while(1){
        printf("~$ ");
        char **input=input_line();
        char *inp=delim(input[0]);
        if(input[0]==NULL){

        }
        if(strcmp(input[0],"cd")==0){

        }
        else if(strcmp(inp,"exit")==0){
            echo(input);
        }
        else if(strcmp(inp,"pwd")==0){
            pwd();
        }
        else if(strcmp(inp,"exit")==0){
            break;
        }
        else if(strcmp(inp,"ls")==0){

        }
        else if(strcmp(inp,"cat")==0){

        }
        else if(strcmp(inp,"date")==0){

        }
        else if(strcmp(inp,"rm")==0){

        }
        else if(strcmp(inp,"mkdir")==0){

        }
        else{
            printf("%s: Command not found\n",inp);
        }

        free(inp);
        free2D(input);
    }
    return 0;
}


