#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("inserire una opzione\n");
        exit(1);
    }
    
    if (argv[1][0] != '-')
    {
        printf("opzione invalida, usare: -opzione\n");
        exit(2);
    }
    int numero = atoi(&argv[1][1]), cont = 0;
    if (numero <= 0)
    {
        printf("inserire un numero strettamente positivo\n");
        exit(3);
    }

char c;
    while (read(0, &c, 1))
    {
        
        if (c == '\n')
        {
            cont += 1;
        }

        write(1,&c,1);

        if (cont == numero)
        {
            break;
        }
    }
    
    return 0;
}
