#include "mod.hpp"

using namespace std;
namespace NB32
{	
	Mod::Mod(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_MOD_MNEMONIC;
	}
	int Mod::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
