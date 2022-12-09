#include "bns.hpp"

using namespace std;
namespace NB32
{	
	Bns::Bns(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BNS_MNEMONIC;
	}
	int Bns::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
