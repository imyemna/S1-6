all: program

program: program.o
	gcc program.o -o program

program.o: program.c
	gcc -c program.c

clean:
	rm -f program.o program
