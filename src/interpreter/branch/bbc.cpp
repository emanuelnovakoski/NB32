#include "bbc.hpp"

using namespace std;
namespace NB32
{	
	Bbc::Bbc(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BBC_MNEMONIC;
	}
	int Bbc::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
