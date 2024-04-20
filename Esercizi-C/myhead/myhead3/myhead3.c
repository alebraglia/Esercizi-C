#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero,fd, cont = 0;
    char c;
    int file = 0;

    if (argc > 3)
    {
        printf("numero parametri invalidi\n");
        exit(1);
    }
    
    
    switch (argc)
    {
    case 1:
        numero = 10;
        break;
    
    case 2:
        if (argv[1][0] == '-')
        {
            numero = atoi(&argv[1][1]);
            if (numero <= 0)
            {
                printf("inserire un numero strettamente positivo\n");
                exit(3);
            }
        }
        else 
        {
            numero = 10;
            file = 1;
        }
        break;

        case 3:
        if (argv[1][0] != '-')
        {
            printf("opzione invalida, usare: -opzione\n");
            exit(4);
        }
        numero = atoi(&argv[1][1]);
        file = 2;
        if (numero <= 0)
        {
            printf("inserire un numero strettamente positivo\n");
            exit(5);
        }
        break;
    }
        
if (file != 0)
{
    if ((fd=open(argv[file],O_RDONLY)) < 0)
    {
        printf("errore nell'apertura del file\n");
        exit(6);
    }
    
}
else fd = 0;

    while (read(fd, &c, 1))
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
