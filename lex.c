#include <stdio.h>
#include "lex.h"

static inline void shift (char c[2]){
	*c = *(c + 1);
	*(c + 1) = fgetc(stdin);
}

int nextword (word_t* w){
	static int init = 1;
	static char c[2];
	if(init){
		c[0] = fgetc(stdin);
		c[1] = fgetc(stdin);
		init = 0;
	}else
		shift(c);
	if(!c[0])
		return 0;
	switch(c[0]){
		case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
		int n = 0;
		for(;c[1]>=48 && c[1]<=57;shift(c))
			n = 10*n + (c[0]-'0');
		n = 10*n + (c[0]-'0');
		w->core.n = n;
		w->type = num;
		break;
		default:
		w->core.k = c[0];
		w->type = key;
	}
	return 1;
}
