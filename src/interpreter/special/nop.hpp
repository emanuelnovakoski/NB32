#ifndef NOP
#define NOP

#include "specialInst.hpp"

namespace NB32
{
	class Nop : public SpecialInst
	{
		public:
			Nop();
			int execute();
	};
}

#endif
