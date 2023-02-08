#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include "Ast2IrConvertor.h"
#include "file.h"
#include "ClassRuntime.h"
#include <libgen.h>

using namespace beingyi;
using namespace antlr4;

FileClass *compileFormContent(const string content) {
    ANTLRInputStream input(content);
    FlyScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    FlyScriptParser parser(&tokens);
    FlyScriptParser::FileContext *tree = parser.file();
    Ast2IrConvertor ast2IrConvertor = Ast2IrConvertor(tree);
    auto *fileClass = ast2IrConvertor.generateFileClass();
    return fileClass;
}

FileClass *compileFormFile(const string &path) {
    char *content = read_txt_content(path.c_str());
    return compileFormContent(content);
}

ClassRuntime createFromContent(string content) {
    auto *fileClass = compileFormContent(content);
    return ClassRuntime(fileClass);
}

ClassRuntime createFromFile(const string &path) {
    char *content = read_txt_content(path.c_str());
    return createFromContent(content);
}


int main(int argc, const char **argv) {
    const char *scriptPath = argv[1];
    //const char *scriptPath="/media/flying/Data/AllProjects/CLionProjects/FlyLanguage/testSrc/whileExpr.txt";
    //const char *scriptPath="/media/flying/Data/AllProjects/CLionProjects/FlyLanguage/testSrc/ifElseExpr.txt";
    //const char *scriptPath="/media/flying/Data/AllProjects/CLionProjects/FlyLanguage/testSrc/whileWithIfElseExpr.txt";
    //const char *scriptPath = "/media/flying/Data/AllProjects/CLionProjects/FlyLanguage/testSrc/methodInvoke.txt";

//    try {
//    auto *ins = new ConstFloatInstruction(1, 1.556f);
    //auto ins2 = ConstIntInstruction(1, 356);

//        printf("ins opcode:%d\n", ins->getOpcode());

    const char *fileNameWithoutExt = strtok(basename(strdup(scriptPath)),".");
    const char *dir = dirname(strdup(scriptPath));
    string irFilePath=fmt::sprintf("%s%s%s%s",dir,"/",fileNameWithoutExt,"_ir.txt");
    char *content = read_txt_content(scriptPath);
    auto *fileClass = compileFormContent(content);
    string fileClassDump = fileClass->dump();
    write_file(irFilePath.c_str(), fileClassDump.data(),
               fileClassDump.size());

    ClassRuntime classRuntime = ClassRuntime(fileClass);
    classRuntime.execute();

//    } catch (std::exception &e) {
//        std::cout << "MyException caught" << std::endl;
//        std::cout << e.what() << std::endl;
//    }

//    sleep(11111);
    return 0;
}
