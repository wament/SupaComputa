CC = gcc
FFLAGS = -O3 -Wall -std=c99
LFFLAG =
OBJECTS = main.o trimatrix.o Hessenberg.o GetShift.o FindZero.o QRA.o QRdecomp.o matrix.o

.PHONY: clean

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -lm -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -lm -c $<

clean:
	rm -f $(OBJECTS) main.exe