#include "bcc.hpp"

using namespace std;
namespace NB32
{	
	Bcc::Bcc(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BCC_MNEMONIC;
	}
	int Bcc::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
