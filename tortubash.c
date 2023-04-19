#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>

int main(){
    while(1){
        printf(">>>");
        char input[256];
        fgets(input, 256, stdin);

        if(strcmp(input,"\n") == 0) continue;

        input[strcspn(input, "\n")] = '\0';

        if(strcmp(input,"EXIT") == 0) exit(0);

        else{
            int id;
            id = fork();
            if(id > 0){
                wait(NULL);
                continue;
            }
            else if(id == 0){
                char *tokens[2];
                char *ptr = strtok(input," ");
                tokens[0] = ptr;
                ptr = strtok(NULL," ");
                tokens[1] = ptr;
                ptr = strtok(NULL," ");
                char path[] = "/home/moises29/Practica_2/";

                if(execl(strcat(path,tokens[0]),tokens[0],tokens[1],NULL) == -1){
                    perror("Este comando no existe");
                    exit(1);
                }
                sleep(3);
		exit(0);
            }
            else{
                perror("Error: No se pudo crear el proceso!");
                exit(1);
            }
        }
    }
}
