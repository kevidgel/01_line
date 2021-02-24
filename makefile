OBJECTS= main.o draw.o display.o
CFLAGS= -Wall
CC= gcc

run: main cool
	./main
	./cool

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

cool: cool.o draw.o display.o
	$(CC) -o cool cool.o draw.o display.o -lm

cool.o: cool.c display.h draw.h ml6.h
	$(CC) -c cool.c -lm

main.o: main.c display.h draw.h ml6.h
	$(CC) -c main.c

draw.o: draw.c draw.h display.h ml6.h
	$(CC) $(CFLAGS) -c draw.c

display.o: display.c display.h ml6.h
	$(CC) $(CFLAGS) -c display.c


clean:
	rm *.o *~
