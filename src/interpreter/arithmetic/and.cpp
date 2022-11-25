#include "and.hpp"

using namespace std;
namespace NB32
{	
	And::And(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_AND_MNEMONIC;
	}
	int And::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
