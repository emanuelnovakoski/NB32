#include "ret.hpp"

using namespace std;
namespace NB32
{	
	Ret::Ret(string instructionString) : SubroutineInst(instructionString)
	{
		this->mnemonic = INST_SUBROUTINE_RET_MNEMONIC;
	}
	int Ret::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
