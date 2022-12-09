#ifndef BZC
#define BZC

#include "branchInst.hpp"

namespace NB32
{
	class Bzc : public BranchInst
	{
		public:
			Bzc(std::string instructionString);
			int execute();
	};
}

#endif
