#include "bcs.hpp"

using namespace std;
namespace NB32
{	
	Bcs::Bcs(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BCS_MNEMONIC;
	}
	int Bcs::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
