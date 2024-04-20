a=sostituisciCar1
all: $a
$a: $a.o
	gcc $a.o -o $a
$a.o: $a.c
	gcc -c $a.c
clean:
	rm -rf *.o
