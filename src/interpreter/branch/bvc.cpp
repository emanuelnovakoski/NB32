#include "bvc.hpp"

using namespace std;
namespace NB32
{	
	Bvc::Bvc(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BVC_MNEMONIC;
	}
	int Bvc::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
