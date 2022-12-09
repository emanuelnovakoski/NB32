#ifndef BBC
#define BBC

#include "branchInst.hpp"

namespace NB32
{
	class Bbc : public BranchInst
	{
		public:
			Bbc(std::string instructionString);
			int execute();
	};
}

#endif
