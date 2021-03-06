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

//definition of function
void shallow_copy(list* node, element elem);

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
	element val;
	val.type = LIST;
	val.l = l;
	//val.a = NULL;
	return val;	
}

/* 3. list cons(element e, list l); that creates a new list whose car and cdr are the
element e and the list l . While the memory for the newly created list is to be allocated
dynamically.
*/
list cons(element e, list l) {
	list new_list = (list)malloc(sizeof(struct _listnode));
	new_list->el = e;
	new_list->next = l;

	//printf("cons :: new list %c \n", new_list->el.a);
	//printf("cons :: new list %c \n", new_list->next->el.a);
	return new_list;
}

/*4. list append(LIST l1, list l2); that creates a new list whose elements are shallow
copies of elements in l2 and l2, appended.
*/
list append(list l1, list l2) {
	list new_list = NULL;
	list first = l1;
	
	while (first != NULL) {
		shallow_copy(&new_list, first->el);
		first = first->next;
	}

	list second = l2;
	while (second != NULL) {
		shallow_copy(&new_list, second->el);
		second = second->next;
	}
	return new_list;
}

//helper function to shallow_copy inside append 
void shallow_copy(list* node, element elem) {
	list val = (list)malloc(sizeof(struct _listnode));
	val->el = elem;
	val->next = NULL;

	if (*node == NULL) {
		*node = val;
	}
	else {
		list temp= *node;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = val;
	}
}

/* 5. element car(element e); that returns head of the list, represented by e; returns
NIL, if e is not a list.
*/
element car(element e) {
	if (e.type == LIST) {
		return e.l->el;
	}
	return NIL;
}

/* 6. list cdr(element e); that returns tail of the list, represented by e.
*/
list cdr(element e) {
	if (e.type != LIST) {
		return NULL;
	}
	else if (e.l == NULL) {
		return NULL;
	}
	return e.l->next;
}

/* 7. list cddr(element e); that similarly returns the cddr of the list, represented by e.
*/
list cddr(element e) {
	// CDDR is composition of two CDR i.e. (CDR (CDR X))
	return cdr(lasel(cdr(e)));
}

/* 8. void print(e); that prints the content of the element e. If e is an atom, it prints the
symbol enclosed in spaces, and if e it is a list, if prints recursively prints the elements
of the list enclosed in parentheses. If e is NIL, the word \NIL" must be printed.
*/
void print(element e) {
	if (e.type == LIST) {
		if (e.l == NULL) {
			printf(" \\NIL \n");
			return;
		}
	}
			
	if (e.type == ATOM) {
		printf(" %c ", e.a);
		return;
	}
	else {
		list temp = e.l;
		printf(" (");
		while (temp != NULL) {
			print(temp->el);
			temp = temp->next;
		}
		printf(") ");
	}	
}

/* 9. void free(LIST l); that frees all the memory previously allocated by the whole list
(including all its elements and its inner lists) 
*/
void lfree(list l) {
	list temp = l;
	while (temp != NULL) {
		if (temp->el.type == LIST) {
			lfree(temp->el.l);
		}

		list val = temp->next;
		free((void*)temp);
		temp = val;
	}
}

/* helper method for testing*/
list create_list(element elem) {
	list val = (list)malloc(sizeof(struct _listnode));
	val->el = elem;
	val->next = NULL;
	return val;

}

void main() {
	printf("Assignment 3\n");

	//Write a short code to create and display the following list:
	printf("\n-------short code to create and display the following list: ---------\n");
	list inner_list = create_list(aasel('b'));
	inner_list->next = create_list(aasel('c'));

	list inner_placeholder = (list)malloc(sizeof(struct _listnode));
	inner_placeholder->el.type = LIST;
	inner_placeholder->el.l = inner_list;

	list main_list = create_list(aasel('a'));
	main_list->next = inner_placeholder;
	inner_placeholder->next = create_list(aasel('d'));
	inner_placeholder->next->next = create_list(aasel('e'));
	print(lasel(main_list));


	//Additionally, print the car and the cdr of the above list; 
	printf("\n--------print the car and the cdr of the above list ---------\n");
	element car_main_list = car(lasel(main_list));
	print(car_main_list);

	printf("\n cdr: ");
	print(lasel(cdr(lasel(main_list))));
	
	//also print the car of the car of the original list.
	printf("\n--------print the car of the car of the original list---------\n");
	element car_car_main_list = car(car_main_list);
	print(car_car_main_list);
	
	lfree(main_list);


	//------------------------------------------------------------------------
	/*
	// 1. test aasel
	printf("\n--------test1---------\n");
	atom a = 'A';
	element e1 = aasel(a);
	print(e1);
		
	// 2. test  lasel
	printf("\n--------test2---------\n");
	list list2 = (list)malloc(sizeof(struct _listnode)); 
	list2->el = aasel('B');
	list2->next = NULL;
	element e2 = lasel(list2);
	print(e2);
	
	// 3. test  cons
	printf("\n--------test3---------\n");
	atom c = 'C';
	element x3 = aasel(c);
	list temp_list = (list)malloc(sizeof(struct _listnode));
	temp_list->el = aasel('D');
	list list3 = cons(x3, temp_list);
	print(list3->el);

	//4. test append
    // first list: (a (b c) d)  
	// second list: (e f g )
	printf("\n--------test4---------\n");
	list c_l = create_list(aasel('c'));
	list sub_first = cons(aasel('b'), c_l);
	list d_l = create_list(aasel('d'));
	list tail = cons(lasel(sub_first), d_l);
	list first = cons(aasel('a'), tail);
		
	// TODO: Isn't print() function supposed to print everything ? 
	list temp = first;
	printf("first list : ");
	while (temp != NULL) {
		print(temp->el);
		temp = temp->next;
	}
	
	// wrong expected output here 
	list second = create_list(aasel('e'));
	list f_l = create_list(aasel('f'));
	list g_l = create_list(aasel('g'));
	second->next = f_l;
	f_l->next = g_l;
	
	
	list temp2 = second;
	printf("\nsecond list : ");
	while (temp2 != NULL) {
		print(temp2->el);
		temp2 = temp2->next;
	}


	list appended_list = append(first, second);
	printf("\nappended list : ");
	list temp3 = appended_list;
	while (temp3 != NULL) {
		print(temp3->el);
		temp3 = temp3->next;
	}
	
	//5. test car 
	//  Input: (1 2 3)  Output: (1)
	printf("\n--------test5---------\n");
	list one = create_list(aasel('1'));
	list two = create_list(aasel('2'));
	list three = create_list(aasel('3'));
	one->next = two;
	two->next = three;
	list list5 = one;
	print(car(lasel(one)));

	//6. test cdr
	//  Input: (5 6 7)  Output: (6 7)
	printf("\n--------test6---------\n");
	list five= create_list(aasel('5'));
	list six = create_list(aasel('6'));
	list seven = create_list(aasel('7'));
	five->next = six;
	six->next = seven;

	//TODO: Isn't print function supposed to do following .. ?
	list list6 = cdr(lasel(five));
	print(lasel(list6));
	
	
	//7. test cddr
	//  Input: (4 8 9)  Output: (9)
	printf("\n--------test7---------\n");
	list w = create_list(aasel('w'));
	list x = create_list(aasel('x'));
	list y = create_list(aasel('y'));
	list z = create_list(aasel('z'));
	w->next = x;
	x->next = y;
	y->next = z;

	list list7 = cddr(lasel(w));
	print(lasel(list7));
		
	//8. test print
	printf("\n--------test8---------\n");
	print(lasel(one));
	printf("\n");
	print(lasel(w));
	printf("\n");
	print(lasel(list6));
	printf("\n");
	print(lasel(list7));

	//9. test free
	printf("\n--------test9---------\n");
	lfree(list2);
	lfree(appended_list);
	lfree(list5);
	lfree(list6);
	lfree(list7);

	*/
}

