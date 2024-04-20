a=selezionaMultipli1
all: $a
main: $a.o
	gcc $a.o -o $a
$a.o: $a.c
	gcc -c $a.c
clean:
	rm -rf *.o
