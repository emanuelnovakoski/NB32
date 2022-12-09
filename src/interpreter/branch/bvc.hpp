#ifndef BVC
#define BVC

#include "branchInst.hpp"

namespace NB32
{
	class Bvc : public BranchInst
	{
		public:
			Bvc(std::string instructionString);
			int execute();
	};
}

#endif
