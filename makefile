CC = gcc
CFLAGS = -Wall -g

connections: main.o libmy_mat.a
	$(CC) $(CFLAGS) main.o libmy_mat.a -o connections -lm
	
my_mat.o: my_mat.h my_mat.c
	$(CC) $(CFLAGS) -c my_mat.c -o my_mat.o

libmy_mat.a: my_mat.o
	ar -rc libmy_mat.a my_mat.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

all: connections my_mat.o main.o libmy_mat.a

clean:
	rm -f  connections *.o *.a

.PHONY: all clean