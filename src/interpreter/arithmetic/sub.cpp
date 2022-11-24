#include "sub.hpp"

using namespace std;
namespace NB32
{	
	Sub::Sub(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_SUB_MNEMONIC;
	}
	int Sub::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
