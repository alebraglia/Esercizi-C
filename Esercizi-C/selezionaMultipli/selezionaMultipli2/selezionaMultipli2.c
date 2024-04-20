#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("inserire 2 parametri\n");
        exit(1);
    }
    

    int fd, n, lung;
    if ((fd = open(argv[1], O_RDONLY)) < 0)	        /* ERRORE se non si riesce ad aprire in LETTURA il file */
		{      
            printf("Errore in apertura file %s dato che fd = %d\n", argv[1], fd);
            exit(2); 
		}

    n = atoi(argv[2]);
    if (n <= 0)
    {
        printf("il valore di %s non è un numero intero positivo\n", argv[2]);
        exit(3);
    }

    lung = lseek(fd,0,SEEK_END);
    char c;

    for (long int i = n; i < lung; i+=n)
    {
        lseek(fd,i - 1,SEEK_SET);
        read(fd, &c, 1);
        printf("Il carattere multiplo %ld-esimo all'interno del file %s e' %c\n",i, argv[1], c);
    }
    
  
    return 0;
}
