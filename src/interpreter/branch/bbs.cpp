#include "bbs.hpp"

using namespace std;
namespace NB32
{	
	Bbs::Bbs(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BBS_MNEMONIC;
	}
	int Bbs::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
