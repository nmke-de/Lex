# Lex

Lex is a simple lexer library that provides one function, `nextword(word_t *)`.

## But why?

Because I can.

## Dependencies

- libc which implements stdio.h
- C compiler

## Build

Type `make`.

## Usage

To see a more interesting example, see [here](https://github.com/nmke-de/rpn).

```C
#include "Lex/lex.h"
#include <stdio.h>

char nextchar(void *dummy) {
	return fgetc(stdin);
}

// Program to return the sum of numbers that occur in input and print any other occuring character.
int main() {
	int sum = 0;
	word_t w;
	
	while (nextword(&w, nextchar, NULL)) {
		if (w.type == num) {
			sum += w.core.n;
		} else if (w.type == key) {
			putc(w.core.k);
		}
	}
	
	return sum;
}
```
