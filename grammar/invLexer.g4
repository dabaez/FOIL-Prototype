lexer grammar invLexer;

COMMA : ',';

VARIABLE : [a-z] [a-z0-9]* ;

CONSTANT : '[' BOOL ( COMMA BOOL )* ']' ;

BOOL : ('0' | '1' | '?');

OR : 'V' ;

AND : '^' ;

NO : '~';

POSITIVE : 'P' ;

OPENP : '(' ;

CLOSEP : ')';

EXISTS : 'EXISTS';

FORALL : 'FORALL';

SUB : '<=';

WHITESPACE : ' ' -> skip ;
