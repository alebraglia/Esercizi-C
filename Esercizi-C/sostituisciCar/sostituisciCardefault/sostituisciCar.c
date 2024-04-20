#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("inserire 2 parametri\n");
        exit(1);
    }
int fd;

    if ((fd = open(argv[1],O_RDWR)) < 0)
    {
        printf("il valore: %s non è un file\n", argv[1]);
        exit(2);
    }
    
    if (strlen(argv[2]) != 1)
    {
        printf("in terzo parametro deve essere un singolo char\n");
        exit(3);
    }

char Cx = argv[2][0], c;
    while (read(fd,&c,1) > 0)
{
    if (c == Cx)
    {
        lseek(fd,-1L,SEEK_CUR);
        write(fd," ",1);
    }
    
}
return 0;

}