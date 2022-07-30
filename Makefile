build: lex.o

lex.o: lex.c
	$(CC) -c -o lex.o lex.c

clean:
	rm lex.o

all: build clean
