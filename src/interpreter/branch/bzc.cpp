#include "bzc.hpp"

using namespace std;
namespace NB32
{	
	Bzc::Bzc(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BZC_MNEMONIC;
	}
	int Bzc::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
