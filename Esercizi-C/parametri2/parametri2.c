#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 4){
        printf("inserire esattamente 3 parametri: \n");
        exit(1);
    }
    int fd,n;
    
    if ((fd = open(argv[1],O_RDONLY)) < 0)
    {
        printf("il valore: %s non è un file\n", argv[1]);
        exit(2);
    }

    n = atoi(argv[2]);
    
    if ((n == 0))
    {
        printf("il valore %s deve essere un intero positivo\n", argv[2]);
        exit(3);
    }

    if (strlen(argv[3]) != 1)
    {
        printf("in terzo parametro deve essere un singolo char\n");
        exit(4);
    }

        
    printf("il nome dell'eseguibile è: %s \n", argv[0]);
    printf("I parametri passati sono: \n");

    printf("il file descriptor ha valore: %d\n", fd);
    printf("il secondo parametro intero ha valore: %d\n", n);
    printf("il singolo carattere C ha valore: %s\n", argv[3]);

    return 0;
}
