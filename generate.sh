#!/bin/sh
set -o errexit


#java -cp $CLASSPATH org.antlr.v4.Tool -Dlanguage=Cpp -listener -visitor -o generated/ -package antlrcpptest TLexer.g4 TParser.g4
#java -cp $CLASSPATH org.antlr.v4.Tool -Dlanguage=Cpp -listener -visitor -o generated/ -package antlrcpptest -XdbgST TLexer.g4 TParser.g4
#java -cp $CLASSPATH org.antlr.v4.Tool -Dlanguage=Java -listener -visitor -o generated/ TLexer.g4 TParser.g4



alias antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.11.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool'
alias grun='java -Xmx500M -cp "/usr/local/lib/antlr-4.11.1-complete.jar:$CLASSPATH" org.antlr.v4.gui.TestRig'

antlr4 -visitor -Dlanguage=Cpp -no-listener -o generated/ -package beingyi FlyScriptParser.g4 FlyScriptLexer.g4