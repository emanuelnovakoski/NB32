#include <iostream>
#include "interpreter.hpp"
using namespace std;
// TODO put return inside if
namespace NB32
{	
	Instruction* interpretSpecial(std::string instructionString)
	{	
		Instruction* instruction = nullptr;
		if (instructionString.compare(4, 8, INST_SPECIAL_NOP_BITCODE) == 0)
			instruction = new Nop();
		if (instructionString.compare(4, 8, INST_SPECIAL_HLT_BITCODE) == 0)
			instruction = new Hlt();
		return instruction;
		
		/*switch(operation)
		{
			case INST_SPECIAL_NOP_BITCODE:
				return new Nop();
			//case INST_SPECIAL_HLT_BITCODE:
			default:
				return nullptr;
		}*/
	}
	
	Instruction* interpretArith(string instructionString)
	{
		Instruction* instruction = nullptr;
		if (instructionString.compare(4, 8, INST_ARITH_ADD_BITCODE) == 0)
			instruction = new Add(instructionString);
		return instruction;
	}	
	
	Instruction* Nb32Interpreter::interpret(std::string instructionString)
	{
		if (instructionString.compare(0, 4, INST_GROUP_SPECIAL) == 0)
		{
			return interpretSpecial(instructionString);
		}
		if (instructionString.compare(0, 4, INST_GROUP_ARITH) == 0)
		{
			return interpretArith(instructionString);
		}
		return nullptr;
		/*
		string group = extractGroup(instructionString);
		switch (group)
		{
			case INST_GROUP_SPECIAL:
				return interpretSpecial(instructionString);
			default:
				return nullptr;
		}*/
	}
	
	
	
	
}
