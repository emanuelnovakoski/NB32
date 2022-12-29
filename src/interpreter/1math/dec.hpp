#ifndef DEC
#define DEC

#include "1MathInst.hpp"

namespace NB32
{
	class Dec : public Math1Inst
	{
		public:
			Dec(std::string instructionString);
			int execute();
	};
}

#endif
