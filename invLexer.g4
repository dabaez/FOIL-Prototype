lexer grammar invLexer;

EXISTS : [Ee] [Xx] [Ii] [Ss] [Tt] [Ss];

FORALL : [Ff] [Oo] [Rr] (' ')* [Aa] [Ll] [Ll];

COUNT : [Cc] [Oo] [Uu] [Nn] [Tt];

COMMA : ',';

VARIABLE : [a-z] [a-z0-9]* ;

BOOL : ('0' | '1' | '?');

OR : 'V' ;

AND : '^' ;

NO : '~';

POSITIVE : 'P' ;

FULL : 'FULL' ;

OPENP : '(' ;

CLOSEP : ')';

OPENB : '[';

CLOSEB : ']';

SUB : '<=';

WHITESPACE : ' ' -> skip ;
