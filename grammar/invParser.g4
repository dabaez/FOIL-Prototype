parser grammar invParser;

options {
	tokenVocab = invLexer;
}

input : quans noquans ;

quans : quan quans | ;

quan :  ( gexists | gforall ) COMMA ;

gexists: EXISTS VARIABLE ;

gforall: FORALL VARIABLE ;

noquans : gor | gand | gno | gpos | gsub;

gor : OPENP noquans CLOSEP OR OPENP noquans CLOSEP;

gand : OPENP noquans CLOSEP AND OPENP noquans CLOSEP;

gno : NO OPENP noquans CLOSEP;

gpos : POSITIVE OPENP (constant | VARIABLE) CLOSEP;

gsub : (constant | VARIABLE) SUB (constant | VARIABLE);

constant : OPENB BOOL ( COMMA BOOL )*  CLOSEB;