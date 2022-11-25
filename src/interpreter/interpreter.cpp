#include <iostream>
#include "interpreter.hpp"
using namespace std;
namespace NB32
{	
	bool isGroup(string instructionString, string group)
	{
		return instructionString.compare(0, 4, group) == 0;
	}
	
	bool isOperation(string instructionString, string operation)
	{
		return instructionString.compare(4, 8, operation) == 0;
	}
	
	Instruction* interpretSpecial(std::string instructionString)
	{	
		if (isOperation(instructionString, INST_SPECIAL_NOP_BITCODE))
			return new Nop();
		if (isOperation(instructionString, INST_SPECIAL_HLT_BITCODE))
			return new Hlt();
		return nullptr;	
	}
	
	Instruction* interpretArith(string instructionString)
	{
		if (isOperation(instructionString, INST_ARITH_ADD_BITCODE))
			return new Add(instructionString);
		if (isOperation(instructionString, INST_ARITH_SUB_BITCODE))
			return new Sub(instructionString);
		if (isOperation(instructionString, INST_ARITH_MUL_BITCODE))
			return new Mul(instructionString);	
		if (isOperation(instructionString, INST_ARITH_DIV_BITCODE))
			return new Div(instructionString);
		if (isOperation(instructionString, INST_ARITH_MOD_BITCODE))
			return new Mod(instructionString);
		if (isOperation(instructionString, INST_ARITH_AND_BITCODE))
			return new And(instructionString);
		if (isOperation(instructionString, INST_ARITH_OR_BITCODE))
			return new Or(instructionString);
		if (isOperation(instructionString, INST_ARITH_XOR_BITCODE))
			return new Xor(instructionString);
		if (isOperation(instructionString, INST_ARITH_ASL_BITCODE))
			return new Asl(instructionString);
		if (isOperation(instructionString, INST_ARITH_ROT_BITCODE))
			return new Rot(instructionString);
		
		return nullptr;
	}	
	
	Instruction* Nb32Interpreter::interpret(std::string instructionString)
	{
		if (isGroup(instructionString, INST_GROUP_SPECIAL))
		{
			return interpretSpecial(instructionString);
		}
		if (isGroup(instructionString, INST_GROUP_ARITH))
		{
			return interpretArith(instructionString);
		}
		return nullptr;
	}
}
