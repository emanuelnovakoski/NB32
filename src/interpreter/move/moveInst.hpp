#ifndef MOVEINST
#define MOVEINST

#include "../instruction.hpp"

namespace NB32
{
	class MoveInst : public Instruction
	{
		private:
			int sreg, dreg, smode, dmode;
		public:
			MoveInst(std::string instructionString);
			std::string instructionAsString();
	};
}

#endif
