#ifndef ASL
#define ASL
#include "arithInst.hpp"


namespace NB32
{
	class Asl : public ArithInst
	{
		public:
			Asl(std::string instructionString);
			int execute();
	};
}

#endif
