//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_IRMETHOD_H
#define FLYLANGUAGE_IRMETHOD_H

#include <fmt/printf.h>
#include "AllInstructions.h"

using namespace std;
using namespace fmt;

class MethodParameter{

private:
    string name;
    int type;

public:
    MethodParameter(string name,int type){
        this->name=name;
        this->type=type;

    }

    const string &getName() const {
        return name;
    }

    int getType() const {
        return type;
    }

};

class IrMethod{

private:
    int returnType;
    string name;
    vector<MethodParameter *> params;
    vector<Instruction *> instructions;

public:
    IrMethod(int returnType, const string &name, const vector<MethodParameter *> &params,
             const vector<Instruction *> &instructions) : returnType(returnType), name(name), params(params),
                                                          instructions(instructions) {

    }

    int getReturnType() const {
        return returnType;
    }

    const string &getName() const {
        return name;
    }

    const vector<MethodParameter *> &getParams() const {
        return params;
    }

    const vector<Instruction *> &getInstructions() const {
        return instructions;
    }

    string dump(){
        string content="";
        content.append(sprintf("%s %s(",ValueType::getName(returnType),name.data()));
        for(MethodParameter *methodParameter:params){
            content.append(sprintf("%s,",ValueType::getName(methodParameter->getType())));
        }
        if(params.size()>0) {
            content.erase(content.size() - 1);
        }
        content.append(sprintf("){\n"));
        int index=0;
        for(Instruction *instruction:instructions){
            content.append(sprintf("%02d    %s\n",index, dumpInstruction(instruction)));
            index++;
        }
        content.append(sprintf("}\n"));
        return content;
    }

};

class IrField{

private:
    string name;
    int type;

public:
    IrField(const string &name, int type) : name(name), type(type) {

    }

    const string &getName() const {
        return name;
    }

    int getType() const {
        return type;
    }

};

class FileClass{

private:
    vector<IrField *> fields;
    vector<IrMethod *> methods;

public:
    StringPool *stringPool = new StringPool();

    FileClass(){

    }

    FileClass(const vector<IrField *> &fields, const vector<IrMethod *> &methods) : fields(fields), methods(methods) {

    }

    void addField(IrField *field){
        fields.push_back(field);
    }

    const vector<IrField *> &getFields() const {
        return fields;
    }

    void addMethod(IrMethod *method){
        methods.push_back(method);
    }

    const vector<IrMethod *> &getMethods() const {
        return methods;
    }

    string dump(){
        string content="";
        for(IrField *field:fields){
            content.append(sprintf("%s %s;\n\n",ValueType::getName(field->getType()),field->getName()));
        }
        for(IrMethod *method:methods){
            content.append(sprintf("%s\n\n",method->dump().data()));
        }
        return content;
    }

    ~FileClass(){
        fields.clear();
        methods.clear();
    }


};


#endif //FLYLANGUAGE_IRMETHOD_H
