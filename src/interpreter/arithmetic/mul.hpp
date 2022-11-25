#ifndef MUL
#define MUL
#include "arithInst.hpp"


namespace NB32
{
	class Mul : public ArithInst
	{
		public:
			Mul(std::string instructionString);
			int execute();
	};
}

#endif
