#ifndef AND
#define AND
#include "arithInst.hpp"


namespace NB32
{
	class And : public ArithInst
	{
		public:
			And(std::string instructionString);
			int execute();
	};
}

#endif
