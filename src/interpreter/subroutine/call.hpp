#ifndef CALL
#define CALL

#include "subroutineInst.hpp"

namespace NB32
{
	class Call : public SubroutineInst
	{
		public:
			Call(std::string instructionString);
			int execute();
	};
}

#endif
