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
    int size=0;
    char *pwd=NULL;
    pwd=getcwd(pwd,size);
    char p=0;
    while(pwd[p]!='\0'){
        printf("%c",p);
        p++;
    }
}

int main(){

    while(1){
        printf("~$ ");
        char **input=input_line();
        if(input[0]==NULL){
            continue;
        }
        if(strcmp(input[0],"cd")==0){

        }
        else if(strcmp(input[0],"echo")){
            echo(input);
        }
        else if(strcmp(input[0],"pwd")==0){
            pwd();
        }
        else if(strcmp(input[0],"exit")==0){
            break;
        }
        else if(strcmp(input[0],"ls")==0){

        }
        else if(strcmp(input[0],"cat")==0){

        }
        else if(strcmp(input[0],"date")==0){

        }
        else if(strcmp(input[0],"rm")==0){

        }
        else if(strcmp(input[0],"mkdir")==0){

        }
        else{
            printf("%s: Command not found\n",input[0]);
        }
    }
    return 0;
}


