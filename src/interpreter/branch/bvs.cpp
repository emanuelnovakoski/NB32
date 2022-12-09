#include "bvs.hpp"

using namespace std;
namespace NB32
{	
	Bvs::Bvs(string instructionString) : BranchInst(instructionString)
	{
		this->mnemonic = INST_BRANCH_BVS_MNEMONIC;
	}
	int Bvs::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
