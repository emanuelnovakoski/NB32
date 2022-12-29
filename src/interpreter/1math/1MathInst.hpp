#ifndef MATH1INST
#define MATH1INST

#include "../instruction.hpp"

namespace NB32
{
	class Math1Inst : public Instruction
	{
		private:
			int reg;
		public:
			Math1Inst(std::string instructionString);
			std::string instructionAsString();
	};
}

#endif
