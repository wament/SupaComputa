CC = mpicc
FFLAGS = -O3 -Wall -std=c99
LFLAGS =
OBJECTS = matrix.o main.o

main: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -lm -o main.exe

main2: main2.o
	$(CC) $(LFLAGS) main2.o -lm -o main2.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main2.o *.exe
