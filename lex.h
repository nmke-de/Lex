#ifndef LEX_H
#define LEX_H
typedef union {
	char k;
	int n;
} wordcore_t;
typedef enum {
	key,
	num
} wordtype_t;
typedef struct {
	wordcore_t core;
	wordtype_t type;
} word_t;

/**
nextword returns whether there are still characters to read.
The first argument is a word_t object, which is manipulated.
The further arguments exist to read in data. This is used
as an interface to allow both buffers and streams as input.
*/
int nextword(word_t *, char (*)(void *), void *);
#endif
