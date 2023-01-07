lexer grammar FlyScriptLexer;
@members {
    int nesting = 0;
}

Type_void: 'void';
Type_string: 'string';
Type_float: 'float';
Type_int: 'int';
Type_boolean: 'boolean';


//KeyWorld:   'if' | 'then' | 'else' | 'return' ;
K_If: 'if';
K_Then: 'then';
K_Else: 'else';
K_Return: 'return';

LCurlyPar: '{';
RCurlyPar: '}';
LSquarePar: '[';
RSquarePar: ']';
PLUS     : '+';
SUBTRACT     : '-';
MULTIPLY     : '*';
DIVIDE     : '/';
NOT     : '!';
AssignEqual: '=';
JudgeEqual: '==';
NotEqual: '!=';
GreaterOrEqual: '>=';
Greater: '>';
LesserOrEqual: '<=';
Lesser: '<';
OrBoolean: '||';
AndBoolean: '&&';
Or: '|';
And: '&';

Comma: ',';
Semicolon: ';';


ID  :   LETTER (LETTER | [0-9])* ;
fragment
LETTER : [a-zA-Z] ;

INT :   [0-9]+ ;

WS  :   [ \t\n\r]+ -> skip ;

SL_COMMENT
    :   '//' .*? '\n' -> skip
    ;


DQUOTE: '"' -> pushMode(IN_STRING);
LPAR: '(' {
    nesting++;
    pushMode(DEFAULT_MODE);
};
RPAR: ')' {
    if (nesting > 0) {
        nesting--;
        popMode();
    }
};

mode IN_STRING;

TEXT: ~[\\"]+ ;
BACKSLASH_PAREN: '\\(' {
    nesting++;
    pushMode(DEFAULT_MODE);
};
ESCAPE_SEQUENCE: '\\' . ;
DQUOTE_IN_STRING: '"' -> type(DQUOTE), popMode;
