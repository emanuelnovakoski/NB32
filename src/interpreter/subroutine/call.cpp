#include "call.hpp"

using namespace std;
namespace NB32
{	
	Call::Call(string instructionString) : SubroutineInst(instructionString)
	{
		this->mnemonic = INST_SUBROUTINE_CALL_MNEMONIC;
	}
	int Call::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
