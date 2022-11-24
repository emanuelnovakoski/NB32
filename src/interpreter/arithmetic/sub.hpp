#ifndef SUB
#define SUB
#include "arithInst.hpp"


namespace NB32
{
	class Sub : public ArithInst
	{
		public:
			Sub(std::string instructionString);
			int execute();
	};
}

#endif
