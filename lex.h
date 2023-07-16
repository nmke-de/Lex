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

int nextword(word_t *w);
#endif
