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
	
	Instruction* interpretBranch(string instructionString)
	{
		if (isOperation(instructionString, INST_BRANCH_BR_BITCODE))
			return new Br(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BZS_BITCODE))
			return new Bzs(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BZC_BITCODE))
			return new Bzc(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BVS_BITCODE))
			return new Bvs(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BVC_BITCODE))
			return new Bvc(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BNS_BITCODE))
			return new Bns(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BNC_BITCODE))
			return new Bnc(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BCS_BITCODE))
			return new Bcs(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BCC_BITCODE))
			return new Bcc(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BBS_BITCODE))
			return new Bbs(instructionString);
		if (isOperation(instructionString, INST_BRANCH_BBC_BITCODE))
			return new Bbc(instructionString);
		return nullptr;
	}
	
	Instruction* interpretMove(std::string instructionString)
	{	
		if (isOperation(instructionString, INST_MOVE_MOVE_BITCODE))
			return new Move(instructionString);
		return nullptr;	
	}
	
	Instruction* interpretSubroutine(std::string instructionString)
	{	
		if (isOperation(instructionString, INST_SUBROUTINE_CALL_BITCODE))
			return new Call(instructionString);
		if (isOperation(instructionString, INST_SUBROUTINE_RET_BITCODE))
			return new Ret(instructionString);
		return nullptr;	
	}
	
	Instruction* interpret1Math(std::string instructionString)
	{	
		if (isOperation(instructionString, INST_1MATH_INC_BITCODE))
			return new Inc(instructionString);
		if (isOperation(instructionString, INST_1MATH_DEC_BITCODE))
			return new Dec(instructionString);
		if (isOperation(instructionString, INST_1MATH_NEG_BITCODE))
			return new Neg(instructionString);
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
		if (isGroup(instructionString, INST_GROUP_BRANCH))
		{
			return interpretBranch(instructionString);
		}
		if (isGroup(instructionString, INST_GROUP_MOVE))
		{
			return interpretMove(instructionString);
		}
		if (isGroup(instructionString, INST_GROUP_SUBROUTINE))
		{
			return interpretSubroutine(instructionString);
		}
		if (isGroup(instructionString, INST_GROUP_1MATH))
		{
			return interpret1Math(instructionString);
		}
		
		return nullptr;
	}
}
