#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char** argv){
    if (argc == 1){
        printf("inserire almeno 1 parametro \n");
        exit(1);
    }
    printf("il nome dell'eseguibile è: %s \n", argv[0]);
    printf("il numero di parametri sono: %d", argc - 1);
    printf("I parametri passati sono: \n");

    for (size_t i = 1; i < argc; i++)
    {
        printf("parametro %d) %s \n", (int)i, argv[i]);
    }
    
}