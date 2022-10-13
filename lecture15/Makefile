CC = gcc
FFLAGS = -O3 -Wall -std=c99
LFFLAG =
OBJECTS = main.o trimatrix.o Hessenberg.o GetShift.o FindZero.o QRA.o QRdecomp.o

.PHONY: clean

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main.exe