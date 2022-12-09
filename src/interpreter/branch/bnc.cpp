#include "bnc.hpp"

using namespace std;
namespace NB32
{	
	Bnc::Bnc(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BNC_MNEMONIC;
	}
	int Bnc::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
