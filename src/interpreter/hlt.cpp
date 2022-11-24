#include "hlt.hpp"


namespace NB32
{	
	Hlt::Hlt()
	{
		this->mnemonic = INST_SPECIAL_HLT_MNEMONIC;
	}
	int Hlt::execute()
	{	
		// halts processor
		return Instruction::CODE_HALT;
	}
}
