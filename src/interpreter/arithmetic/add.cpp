#include "add.hpp"

using namespace std;
namespace NB32
{	
	Add::Add(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_ADD_MNEMONIC;
	}
	int Add::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
