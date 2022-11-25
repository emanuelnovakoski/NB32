#ifndef OR
#define OR
#include "arithInst.hpp"


namespace NB32
{
	class Or : public ArithInst
	{
		public:
			Or(std::string instructionString);
			int execute();
	};
}

#endif
