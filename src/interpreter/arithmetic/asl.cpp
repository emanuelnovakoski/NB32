#include "asl.hpp"

using namespace std;
namespace NB32
{	
	Asl::Asl(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_ASL_MNEMONIC;
	}
	int Asl::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
