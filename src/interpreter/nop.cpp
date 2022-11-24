#include "nop.hpp"


namespace NB32
{	
	Nop::Nop()
	{
		this->mnemonic = INST_SPECIAL_NOP_MNEMONIC;
	}
	void Nop::execute()
	{	
		// does nothing
		return;
	}
}
