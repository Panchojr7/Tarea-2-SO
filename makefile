CC = gcc
CFLAGS = -pthread -Wall
clean:
	rm -f *.o
%.o: %.c
	gcc -g -Wall -Werror -D_POSIX_PTHREAD_SEMANTICS $^ -c -o $@
main: sthread.o main.o
	$(CC) $(CFLAGS) $^ -o exe

