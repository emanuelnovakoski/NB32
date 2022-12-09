#include "bzs.hpp"

using namespace std;
namespace NB32
{	
	Bzs::Bzs(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BZS_MNEMONIC;
	}
	int Bzs::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
