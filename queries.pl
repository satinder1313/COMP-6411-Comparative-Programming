% 4.2 Executing queries
/*
compile file using :
[facts].
*/

/*
Keeping all the queries as comments here:
1. What classes, if any, are present in the program ?
note: (use ; semicolon to print all)

type
*/
%query: class(X).
setof(class(X)).

2. What methods, if any, does 'Human' define ?
query: defines(human,X,method,_).
note: (use ; semicolon to print all)

3. Does class 'Android' define an attribute named 'version'?
query: defines(android,version,attribute,_).
note: if it doesn't print false means it is true ? (cuz wrong value is return false) like this query: defines(android,version2,attribute,_).

4. Does the 'Machine' define a method named 'hasMemories()' ?
query: defines(machines, hasMemories,method,_).
note: result should be false, because machine doesn't have a method named 'hasMemories'

5. Which class, if any, extends class 'Human' ?
query: extends(X,human).
note: (use ; semicolon to print all) although it has only one value.

6. Which type, if any, implements interface Behavior2?
query: implements(X,behavior2).
note: (use ; semicolon to print all) although it has only one value.
*/

