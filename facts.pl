% Ritika, Satinder, Binit, Nilesh
% 4.1 Declarative database

interface('Behavior').
interface('Behavior2').

class('Human').
class('Bladerunner').
class('Machine').
class('Android').
class('Android2').

implements('Human','Behavior').
implements('Machine','Behavior').
implements('Android2','Behavior2').

extends('Bladerunner','Human').
extends('Android','Machine').
extends('Android2','Android').

defines('Behaviour','act()',method,public).
defines('Behaviour','reason()',method,public).

defines('Human',type,attribute,public).
defines('Human',empathy,attribute,public).
defines('Human','act()',method,public).
defines('Human','reason()',method,public).
defines('Human','hasEmpathy()',method,public).

defines('Bladerunner',type,attribute,public).
defines('Bladerunner',rank,attribute,public).
defines('Bladerunner','reason()',method,public).

defines('Machine',type,attribute,public).

defines('Android',version,attribute,public).
defines('Android','whatIhave()',method,public).
defines('Android','whatIneed()',method,public).
defines('Android','act()',method,public).
defines('Android','reason()',method,public).

defines('Behavior2',empathy,attribute,public).
defines('Behavior2',memories,attribute,public).
defines('Behavior2','hasEmpathy()',method,public).
defines('Behavior2','hasMemories()',method,public).

defines('Android2','whatIhave()',method,public).
defines('Android2','hasEmpathy()',method,public).
defines('Android2','hasMemories()',method,public).

construction('Bladerunner',default).
construction('Bladerunner','string').

construction('Android','int').
construction('Android2','int').
construction('Android2',default).


% 4.2 Executing queries
/*
compile file using :
[facts].

Keeping all the queries as comments here:
1. What classes, if any, are present in the program ?
query: class(X).
note: (use ; semicolon to print all)

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

