all: lex

lex: lex.c
	$(CC) -c -o lex.o lex.c
