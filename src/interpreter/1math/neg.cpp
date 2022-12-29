#include "neg.hpp"

using namespace std;
namespace NB32
{	
	Neg::Neg(string instructionString) : Math1Inst(instructionString)
	{
		this->mnemonic = INST_1MATH_NEG_MNEMONIC;
	}
	int Neg::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
