#ifndef BZS
#define BZS

#include "branchInst.hpp"

namespace NB32
{
	class Bzs : public BranchInst
	{
		public:
			Bzs(std::string instructionString);
			int execute();
	};
}

#endif
