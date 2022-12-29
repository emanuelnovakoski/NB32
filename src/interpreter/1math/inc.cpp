#include "inc.hpp"

using namespace std;
namespace NB32
{	
	Inc::Inc(string instructionString) : Math1Inst(instructionString)
	{
		this->mnemonic = INST_1MATH_INC_MNEMONIC;
	}
	int Inc::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
