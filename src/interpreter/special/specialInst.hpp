#ifndef SPECIALINST
#define SPECIALINST

#include "../instruction.hpp"
namespace NB32
{
	class SpecialInst : public Instruction
	{
		public:
			SpecialInst();
			std::string instructionAsString();
		
	};
}

#endif
