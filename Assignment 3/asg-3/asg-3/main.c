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
element aasel(atom a) {	
	element val;
	val.type = ATOM;
	val.l = NULL;
	val.a = a;
	printf("aasel::val : %c\n", val.a);
	return val;
}

/* 2. element lasel(list l); AKA list as element, returns an element whose content is
set to the list, pointed by l .
*/
element lasel(list l) {
	element val;
	val.type = ATOM;
	val.l = l;
	printf("lasel:: val : %c \n", val.a);
	return val;	
}

/* 3. list cons(element e, list l); that creates a new list whose car and cdr are the
element e and the list l . While the memory for the newly created list is to be allocated
dynamically.
*/
list cons(element e, list l) {
	e.l = l;
	list new_list;
	new_list = (list)malloc(sizeof(struct _listnode));
	new_list->el = e;
	new_list->next = l;

	printf("cons :: new list %c \n", new_list->el.a);
	printf("cons :: new list %c \n", new_list->next->el.a);
	return new_list;

}

void main() {
	printf("Assignment 3\n");

	// 1. aasel
	atom a = 'A';
	element x1 = aasel(a);
	printf(" atom: %c\n", x1.a);
	
	// 2. lasel
	list l1; 
	l1 = (list)malloc(sizeof(struct _listnode)); 
	l1->el = x1;
	l1->next = NULL;
	element x2 = lasel(l1);
	printf("element's atom %c\n", l1->el.a);	

	// 3. cons
	atom b = 'B';
	element x3 = aasel(b);
	list l2 = cons(x3, l1);
}

