//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_ALLINSTRUCTIONS_H
#define FLYLANGUAGE_ALLINSTRUCTIONS_H

#include "NopInstruction.h"
#include "BreakInstruction.h"
#include "ConstStringInstruction.h"
#include "ConstIntInstruction.h"
#include "ConstFloatInstruction.h"
#include "ConstBooleanInstruction.h"
#include "ConstParamInstruction.h"
#include "MoveResultObjectInstruction.h"
#include "MoveInstruction.h"
#include "InvokeInstruction.h"
#include "PlusInstruction.h"
#include "SubInstruction.h"
#include "BoolInstruction.h"
#include "IfInstruction.h"
#include "IfNotInstruction.h"
#include "GotoInstruction.h"
#include "SetFieldInstruction.h"
#include "GetFieldInstruction.h"
#include "ReturnInstruction.h"


extern string dumpInstruction(Instruction *instruction);


#endif //FLYLANGUAGE_ALLINSTRUCTIONS_H
