lexer grammar invLexer;

COMMA : ',';

VARIABLE : [a-z] [a-z0-9]* ;

CONSTANT : '[' ('0'|'1') ( ',' ('0'|'1') )? ']' ;

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
