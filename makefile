fib_list: fib_list.o
	gcc -g -Wall -ansi -pedantic fib_list.o -o fib_list

fib_list.o: fib_list.c
	gcc -c -Wall -ansi -pedantic fib_list.c -o fib_list.o
