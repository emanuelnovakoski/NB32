#ifndef BRANCHINST
#define BRANCHINST

#include "../instruction.hpp"
namespace NB32
{
	class BranchInst : public Instruction
	{
		private:
			int reg, mode;
		public:
			BranchInst(std::string instructionString);
			std::string instructionAsString();
	};
}

#endif
