#include <iostream>

#include "Ast2IrConvertor.h"
#include "file.h"
#include "ClassRuntime.h"

using namespace beingyi;
using namespace antlr4;

ClassRuntime createFromContent(string content) {
    ANTLRInputStream input(content);
    FlyScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    FlyScriptParser parser(&tokens);
    FlyScriptParser::FileContext *tree = parser.file();
    Ast2IrConvertor ast2IrConvertor = Ast2IrConvertor(tree);
    auto fileClass = ast2IrConvertor.generateFileClass();
    return ClassRuntime(fileClass);
}

ClassRuntime createFromFile(string path) {
    char *content = read_txt_content(path.c_str());
    return createFromContent(content);
}


int main(int , const char **) {

    auto opcode = Opcode::ConstString;

    printf("opcode:%s\n", Opcode::getOpcodeName(opcode));
    try {
        auto *ins = new ConstStringInstruction(1, "hello world");
        //auto ins2 = ConstIntInstruction(1, 356);

        printf("ins opcode:%d\n", ins->getOpcode());

        string dumpString = dump(ins);
        const char *data = dumpString.c_str();
        printf("ins:%s\n", data);
        printf("ins:%s\n", dumpString.c_str());
        printf("ins:%s\n", dump(ins).c_str());


        char *content=read_txt_content("/media/flying/Data/AllProjects/CLionProjects/FlyLanguage/test.txt");

        ClassRuntime classRuntime= createFromContent(content);
        classRuntime.execute();

    } catch (std::exception &e) {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }

    return 0;
}
