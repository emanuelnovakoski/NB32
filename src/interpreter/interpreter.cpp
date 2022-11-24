#include <iostream>
#include "interpreter.hpp"
#include "hlt.hpp"
using namespace std;
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
	
	Instruction* Nb32Interpreter::interpret(std::string instructionString)
	{
		if (instructionString.compare(0, 4, INST_GROUP_SPECIAL) == 0)
		{
			return interpretSpecial(instructionString);
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
