parser grammar invParser;

options {
	tokenVocab = invLexer;
}

input : quans noquans ;

quans : quan quans | ;

quan : (EXISTS | FORALL) VARIABLE COMMA ;

noquans : gor | gand | gno | gpos | gsub;

gor : OPENP noquans CLOSEP OR OPENP noquans CLOSEP;

gand : OPENP noquans CLOSEP AND OPENP noquans CLOSEP;

gno : NO OPENP noquans CLOSEP;

gpos : POSITIVE OPENP (CONSTANT | VARIABLE) CLOSEP;

gsub : (CONSTANT | VARIABLE) SUB (CONSTANT | VARIABLE);
