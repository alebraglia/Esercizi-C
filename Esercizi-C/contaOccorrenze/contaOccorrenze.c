#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("inseire 2 parametri\n");
        exit(1);
    }

int fd;
long int cont;

    if ((fd = open(argv[1],O_RDONLY)) < 0)
    {
        printf("il valore: %s non è un file\n", argv[1]);
        exit(2);
    }
    
if (strlen(argv[2]) != 1)
    {
        printf("in terzo parametro deve essere un singolo char\n");
        exit(3);
    }
char Cx = argv[2][0];

printf("il nome dell'eseguibile è: %s \n", argv[0]);
    printf("I parametri passati sono: \n");

    printf("il file di nome: %s\n", argv[1]);
    printf("il singolo carattere Cx ha valore: %c\n", Cx);

char c;

while ((read(fd,&c,1)) > 0)
{
    if (c == Cx)
    {
        ++cont;
    }
    
}

printf("il numero di occorrenze è: %ld\n", cont);

    return 0;

}
