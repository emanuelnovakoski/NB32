#include "or.hpp"

using namespace std;
namespace NB32
{	
	Or::Or(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_OR_MNEMONIC;
	}
	int Or::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
