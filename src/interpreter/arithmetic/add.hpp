#ifndef ADD
#define ADD
#include "arithInst.hpp"


namespace NB32
{
	class Add : public ArithInst
	{
		public:
			Add(std::string instructionString);
			int execute();
	};
}

#endif
