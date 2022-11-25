#ifndef XOR
#define XOR
#include "arithInst.hpp"


namespace NB32
{
	class Xor : public ArithInst
	{
		public:
			Xor(std::string instructionString);
			int execute();
	};
}

#endif
