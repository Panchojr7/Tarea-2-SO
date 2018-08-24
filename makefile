CC = gcc
CFLAGS = -pthread -Wall
clean:
	rm -f *.o
%.o: %.c
	gcc -g -Wall -Werror -D_POSIX_PTHREAD_SEMANTICS $^ -c -o $@
orden: sthread.o orden.o
	$(CC) $(CFLAGS) $^ -o exe
funcion: sthread.o funcion.o
	$(CC) $(CFLAGS) $^ -o exe
