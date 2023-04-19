#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int pid = getpid();
    printf("%d\n",pid);
    exit(0);
}
