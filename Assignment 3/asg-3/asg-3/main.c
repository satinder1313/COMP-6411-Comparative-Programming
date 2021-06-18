#include <stdio.h>
#include <stdlib.h>

typedef enum { ATOM, LIST } eltype;
typedef char atom;

struct _listnode;
typedef struct {
	eltype type;
	union {
		atom a;
		struct _listnode* l;
	};
} element;

typedef struct _listnode {
	element el;
	struct _listnode* next;
} *list;

const element NIL = { .type = LIST, .l = NULL };


/* 1. element aasel(atom a); AKA atom as element, returns an element whose content
	is set to atom a.
*/
element aasel(atom ch) {	
		
	element val;
	val.type = ATOM;
	val.l = NULL;
	val.a = ch;
	//printf(" val : %c\n", val.a);
	return val;
}


void main() {
	printf("Assignment 3\n");

	// 1. aasel
	atom a = 'A';
	element x = aasel(a);
	printf(" atom: %c\n", x.a);
	
	// 2. lasel
}

