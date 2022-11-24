#include "nop.hpp"


namespace NB32
{	
	Nop::Nop()
	{
		this->mnemonic = INST_SPECIAL_NOP_MNEMONIC;
	}
	int Nop::execute()
	{	
		// does nothing
		return Instruction::CODE_OK;
	}
}
