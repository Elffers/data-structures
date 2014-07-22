CC = clang
list: main.o list.o
	$(CC) main.o list.o -o list

main.o: main.c list.h
	$(CC) main.c -o main.o -c

list.o: list.c list.h
	$(CC) list.c -o list.o -c

clean:
	-rm -f main.o list.o list
