lexer grammar invLexer;

COMMA : ',';

VARIABLE : [a-z] [a-z0-9]* ;

BOOL : ('0' | '1' | '?');

OR : 'V' ;

AND : '^' ;

NO : '~';

POSITIVE : 'P' ;

OPENP : '(' ;

CLOSEP : ')';

OPENB : '[';

CLOSEB : ']';

EXISTS : 'EXISTS';

FORALL : 'FORALL';

SUB : '<=';

WHITESPACE : ' ' -> skip ;
