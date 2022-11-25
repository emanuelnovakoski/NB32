#ifndef DIV
#define DIV
#include "arithInst.hpp"


namespace NB32
{
	class Div : public ArithInst
	{
		public:
			Div(std::string instructionString);
			int execute();
	};
}

#endif
