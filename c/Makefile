CC = clang
list: main.o list.o
	$(CC) main.o list.o -o list

# main.o: main.c list.h
# 	$(CC) main.c -o main.o -c
# 
# list.o: list.c list.h
# 	$(CC) list.c -o list.o -c

# This indicates that any object file depends on a .c file of the same name.
# The $@ indicates the output file and $< indicates input file. The order
# of these two does not matter. It is equivalent to the above two rules.

%.o: %.c list.h
	$(CC) -o $@ $< -c

clean:
	-rm -f main.o list.o list
