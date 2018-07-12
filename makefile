CC = gcc
CFLAGS = -pthread -Wall
clean:
	rm -f *.o
%.o: %.c
	gcc -g -Wall -Werror -D_POSIX_PTHREAD_SEMANTICS $^ -c -o $@
main2: sthread.o main2.o
	$(CC) $(CFLAGS) $^ -o exe

