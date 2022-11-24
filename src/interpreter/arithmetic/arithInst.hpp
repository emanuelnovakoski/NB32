#ifndef ARITHINST
#define ARITHINST

#include <iostream>
#include "../instruction.hpp"
namespace NB32
{
	class ArithInst : public Instruction
	{
		private:
			int rega, regb, regr;
	
		public:
			ArithInst(std::string instructionString);
			std::string instructionAsString();
	};
}

#endif
