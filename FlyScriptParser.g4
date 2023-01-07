/** Simple statically-typed programming language with functions and variables
 *  taken from "Language Implementation Patterns" book.
 */
parser grammar FlyScriptParser;

options {
    tokenVocab = 'FlyScriptLexer';
}

file:   (function | field | stat)+ ;

//varDecl
//    :   Type ID ('=' expr)? ';' #varStmt
//    ;

//type: 'string' | 'float' | 'int' | 'void' ;
type: Type_void | Type_string | Type_float | Type_int | Type_boolean ;

field
    :   type ID ('=' expr)? ';'
    ;

function
    :   type ID '(' functionParameters? ')' block // "void f(int x) {...}"
    ;
functionParameters
    :   functionParameter (',' functionParameter)*
    ;
functionParameter
    :   type ID
    ;

block:  '{' stat* '}' ;   // possibly empty statement block
stat
    :
    block #codeBlock
    |   type ID ('=' expr)? ';' #varStmt
    |   'if' '(' expr ')' block ('else' block)? #ifElseStmt
    |   'return' expr? ';' #returnStmt
    |   expr '=' expr ';' #assignStmt // assignment
    |   expr ';' #invokeStmt         // func call
    ;

judgeSymbol: '==' #judgeEqualSymbol
    | '!=' #notEqualSymbol
    | '>=' #greaterOrEqualSymbol
    | '>' #greaterSymbol
    | '<=' #lesserOrEqualSymbol
    | '<' #lesserSymbol
    ;

expr:   ID '(' exprList? ')' #invokeExpr   // func call like f(), f(x), f(1,2)
    |   ID '[' expr ']' #arrayGetExpr         // array index like a[i], a[i][j]
    |   '!' expr #notExpr               // boolean not
    |   expr ('*'|'/') expr #mulDivExpr
    |   expr ('+'|'-') expr #plusSubExpr
    |   expr ('|') expr #orExpr
    |   expr ('&') expr #andExpr
    |   expr judgeSymbol expr   #booleanExpr
    |   expr '||' expr #orBooleanExpr
    |   expr '&&' expr #andBooleanExpr
    |   ID #identifierExpr                     // variable reference
    |   INT #intExpr
    |   DQUOTE stringContents* DQUOTE #stringExpr
    |   '(' expr ')' #parensExpr
    ;

exprList : expr (',' expr)* ;   // arg list

stringContents : TEXT
               | ESCAPE_SEQUENCE
               | '\\(' expr ')'
               ;

