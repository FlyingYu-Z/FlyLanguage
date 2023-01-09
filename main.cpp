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
    auto *fileClass = ast2IrConvertor.generateFileClass();
    string fileClassDump=fileClass->dump();
    write_file("/media/flying/Data/AllProjects/CLionProjects/FlyLanguage/test_ins.txt",fileClassDump.data(),fileClassDump.size());
    return ClassRuntime(fileClass);
}

ClassRuntime createFromFile(string path) {
    char *content = read_txt_content(path.c_str());
    return createFromContent(content);
}


int main(int argc, const char **argv) {
    const char *scriptPath=argv[1];

//    try {
        auto *ins = new ConstFloatInstruction(1, 1.556f);
        //auto ins2 = ConstIntInstruction(1, 356);

//        printf("ins opcode:%d\n", ins->getOpcode());

        string dumpString = dumpInstruction(ins);
        const char *data = dumpString.c_str();
        printf("ins:%s\n", data);
//        printf("ins:%s\n", dumpString.c_str());
//        printf("ins:%s\n", dump(ins).c_str());


        char *content=read_txt_content(scriptPath);

        ClassRuntime classRuntime= createFromContent(content);
        classRuntime.execute();

//    } catch (std::exception &e) {
//        std::cout << "MyException caught" << std::endl;
//        std::cout << e.what() << std::endl;
//    }

    return 0;
}
