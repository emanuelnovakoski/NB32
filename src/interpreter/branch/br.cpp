#include "br.hpp"

using namespace std;
namespace NB32
{	
	Br::Br(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BR_MNEMONIC;
	}
	int Br::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
