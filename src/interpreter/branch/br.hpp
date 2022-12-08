#ifndef BR
#define BR

#include "branchInst.hpp"

namespace NB32
{
	class Br : public BranchInst
	{
		public:
			Br(std::string instructionString);
			int execute();
	};
}

#endif
