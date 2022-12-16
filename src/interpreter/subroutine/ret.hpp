#ifndef RET
#define RET

#include "subroutineInst.hpp"

namespace NB32
{
	class Ret : public SubroutineInst
	{
		public:
			Ret(std::string instructionString);
			int execute();
	};
}

#endif
