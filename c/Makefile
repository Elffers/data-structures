CC = clang

array_stack: array_stack_main.o array_stack.o
	$(CC) array_stack_main.o array_stack.o -o array_stack

# including the header (.h) file is not necessary when compiling
# the source files by hand, but it's necessary in the Makefile 
# because it doesn't know about the dependencies automatically. 
# So if anything gets changed in the .h file, the compiler needs 
# to rebuild the files.

array_stack_main.o: array_stack_main.c array_stack.h
	$(CC) array_stack_main.c -o array_stack_main.o -c

array_stack.o: array_stack.c array_stack.h
	$(CC) array_stack.c -o array_stack.o

clean:
	rm -rf array_stack.o array_stack_main.o array_stack
