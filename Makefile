CC = gcc
CFLAGS = -Wall
OBJ = main.o read_png.o
EXEC = program


$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)


main.o: main.c read_png.h
	$(CC) -c main.c $(CFLAGS)

read_png.o: read_png.c read_png.h
	$(CC) -c read_png.c $(CFLAGS)


clean:
	rm -f *.o $(EXEC)