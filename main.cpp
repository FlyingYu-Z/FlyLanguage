#include <iostream>

#include "Ast2IrConvertor.h"
#include "file.h"

using namespace beingyi;
using namespace antlr4;


int main(int , const char **) {
    char *content=read_txt_content("/media/flying/Data/AllProjects/CLionProjects/FlyLanguage/test.txt");
    ANTLRInputStream input(content);
    FlyScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();

    FlyScriptParser parser(&tokens);
    FlyScriptParser::FileContext* tree =parser.file();

    Ast2IrConvertor ast2IrConvertor=Ast2IrConvertor(tree);
    auto fileClass=ast2IrConvertor.generateFileClass();


    return 0;
}
