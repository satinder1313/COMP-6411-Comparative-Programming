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
	return val;
}

/* 2. element lasel(list l); AKA list as element, returns an element whose content is
set to the list, pointed by l .
*/
element lasel(list l) {
	element val = { .type = LIST, .l = l };
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

/*4. list append(LIST l1, list l2); that creates a new list whose elements are shallow
copies of elements in l2 and l2, appended.

 TODO : revise this !
*/
list append(list l1 , list l2) {
	l1->next = l2;
	return l1;
}

/* 5. element car(element e); that returns head of the list, represented by e; returns
NIL, if e is not a list.
*/
element car(element e) {
	if (e.type == LIST) {
		return e.l->el;
	}
	else {
		return NIL;
	}
}

/* 6. list cdr(element e); that returns tail of the list, represented by e.
*/
list cdr(element e) {
	if (e.type == LIST) {
		return e.l;
	}	
}

/* 7. list cddr(element e); that similarly returns the cddr of the list, represented by e.
*/
list cddr(element e) {
	// CDDR is composition of two CDR i.e. (CDR (CDR X))
	list new_list = cdr(e);
	return cdr(new_list->el);

}

/* 8. void print(e); that prints the content of the element e. If e is an atom, it prints the
symbol enclosed in spaces, and if e it is a list, if prints recursively prints the elements
of the list enclosed in parentheses. If e is NIL, the word \NIL" must be printed.
*/
void print(element e) {
	if (e.type == ATOM) {
		printf(" (%c)  \n", e.a);
	}
	else if (e.type == LIST) {
		if (e.l == NULL) {
			printf("\\NIL \n");
		}
		else {
			printf(" (%c)  \n", e.a);
			print(e.l->el);
		}		
	}	
}

/* 9. void free(LIST l); that frees all the memory previously allocated by the whole list
(including all its elements and its inner lists) 
*/
void free(list l) {
	if (l != NULL) {
		list new_list = l->next;
		free(new_list);
	}
}

void main() {
	printf("Assignment 3\n");

	// 1. test aasel
	atom a = 'A';
	element x1 = aasel(a);
	printf("assel's atom: %c\n", x1.a);
	
	// 2. test  lasel
	list l1 = (list)malloc(sizeof(struct _listnode)); 
	l1->el = aasel(a);
	element x2 = lasel(l1);
	printf("lasel's list  %c\n", l1->el.a);	

	// 3. test  cons
	atom b = 'B';
	element x3 = aasel(b);
	list l2 = cons(x3, l1);
}

