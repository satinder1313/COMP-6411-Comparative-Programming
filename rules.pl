% Ritika, Satinder, Binit, Nilesh

% 4.3 Extend the database with rules

:- consult(facts).

/*1. empty class/1: Succeeds when a type defines no features
 */
empty_class(X):- class(X),findall(X, defines(X,_,_,_),L),length(L,N),N==0.

/*2. lazy class/1: Succeeds when a type defines only one method.
 */
lazy_class(X):-class(X),findall(X,defines(X,_,method,_),L),length(L,N),N==1.

/*3. data type/1: Succeeds when a type defines attributes, but does not define any methods
 */
data_type(X):-class(X),findall(X,defines(X,_,method,_),L),length(L,N),N==0,findall(X,defines(X,_,attribute,_),L1),length(L1,N1),N1>=1.

/*4. child/1 Succeeds by finding a set of direct subtype-supertype pairs.
*/
child(Set):- setof((X,Y),extends(X,Y),Set1),setof((X,Y),implements(X,Y),Set2),union(Set1,Set2,Set).

/*5. child/2: Succeeds when it finds a subtype relationship
 */
child(X,Y):- extends(X,Y).
child(X,Y):- implements(X,Y).

/*6. ancestor/2: Succeeds when it finds all ancestors of a given type
(Hint: Uses child/2).
 */
ancestor(X,Y):- child(Y,X).
ancestor(X, Y) :- child(Z,X), ancestor(Z, Y).

/*7. state of/2: Succeeds by obtaining the state of a given type. Recall that the state of
a class consists of all attributes defined or inherited.
*/
state_of(X,States):-findall(L,(defines(X,L,attribute,public);(extends(X,Y),defines(Y,L,attribute,public));(implements(X,Z),defines(Z,L,attribute,public))),States).

/*8. interface of/2 Succeeds when List contains a list of all messages (method calls)
that make up the interface of class Type.
*/
interface_of(X,Interface):-findall(L,(defines(X,L,method,public);(extends(X,Y),defines(Y,L,method,public));(implements(X,Z),defines(Z,L,method,public))),List),list_to_set(List,Interface).

/*9. siblings/1: Succeeds by obtaining a pair of sibling types.
*/
siblings(Set):-setof((X,Y),(implements(X,A),implements(Y,A),X\==Y),Set).

/*10. instantiated polymorphically /1: Succeeds when a type is instantiated using polymorphism
 */
instantiated_polymorphically(X):- extends(X,_).

is_type(X):-class(X).
is_type(X):-interface(X).

/*11. root/1: Succeeds by finding a type with no ancestors. Uses is type/1 which succeeds
when a type is either a class or an interface.
*/
root(X):-is_type(X),not(extends(X,_)),not(implements(X,_)).

/*12. provides interface/2: Succeeds by obtaining a list of all classes that implement a
given interface
*/
provides_interface(X, Y) :-
    findall(L, implements(L, X), M),
    findall(Name, (member(N, M), ancestor(N, Name)), Desc),
    append(M, Desc, Y);
    false.
