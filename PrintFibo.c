#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){
    if(argc != 2){
        perror("Debe ingresar argumentos");
        exit(EXIT_FAILURE);
    }
    int a, b, c, i, tope;
    tope = atoi(argv[1]);
    a = 0;
    b = 1;
    for(i=0; i<tope; i++){
        c = a + b;
        a = b;
        b = c;
    }
    printf("%d\n",a);

    exit(0);
}
