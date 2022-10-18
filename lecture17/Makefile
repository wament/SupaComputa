CC = gcc
FFLAGS = -Wall -std=c99 -fopenmp
LFFLAGS = -lgomp -lm
OBJECTS = forloop.o matrix.o

.PHONY: clean

main.exe: $(OBJECTS)
	$(CC) $(LFFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:
	rm -f $(OBJECTS) *.exe