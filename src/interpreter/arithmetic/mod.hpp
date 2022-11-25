#ifndef MOD
#define MOD
#include "arithInst.hpp"


namespace NB32
{
	class Mod : public ArithInst
	{
		public:
			Mod(std::string instructionString);
			int execute();
	};
}

#endif
