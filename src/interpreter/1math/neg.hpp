#ifndef NEG
#define NEG

#include "1MathInst.hpp"

namespace NB32
{
	class Neg : public Math1Inst
	{
		public:
			Neg(std::string instructionString);
			int execute();
	};
}

#endif
