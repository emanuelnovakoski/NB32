#include "dec.hpp"

using namespace std;
namespace NB32
{	
	Dec::Dec(string instructionString) : Math1Inst(instructionString)
	{
		this->mnemonic = INST_1MATH_DEC_MNEMONIC;
	}
	int Dec::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
