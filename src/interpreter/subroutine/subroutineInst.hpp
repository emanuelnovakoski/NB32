#ifndef SUBROUTINST
#define SUBROUTINST

#include "../instruction.hpp"

namespace NB32
{
	class SubroutineInst : public Instruction
	{
		private:
			int reg, mode;
			std::string getregAsString(int reg, int mode);
		public:
			SubroutineInst(std::string instructionString);
			std::string instructionAsString();
	};
}

#endif
