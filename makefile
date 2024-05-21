CC=gcc
CFLAGS=-Wall

all: calculator-det-matrix

calculator-det-matrix: calculator-det-matrix.o
	$(CC) $(CFLAGS) -o calculator-det-matrix calculator-det-matrix.o

calculator-det-matrix.o: calculator-det-matrix.c
	$(CC) $(CFLAGS) -c calculator-det-matrix.c

clean:
	rm -f calculator-det-matrix calculator-det-matrix.o
