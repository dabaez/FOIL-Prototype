parser grammar invParser;

options {
	tokenVocab = invLexer;
}

input : quans;

quans : ( quan quans ) | ( noquans );

quan :  ( gexists | gforall ) COMMA ;

gexists: EXISTS VARIABLE ;

gforall: FORALL VARIABLE ;

noquans : gor | gand | gno | gpos | gsub;

gor : OPENP noquans CLOSEP OR OPENP noquans CLOSEP;

gand : OPENP noquans CLOSEP AND OPENP noquans CLOSEP;

gno : NO OPENP noquans CLOSEP;

gpos : POSITIVE OPENP cov CLOSEP;

gsub : cov SUB cov;

cov : (constant | VARIABLE);

constant : OPENB BOOL ( COMMA BOOL )*  CLOSEB;