#include "specialInst.hpp"

namespace NB32
{
	class Nop : public SpecialInst
	{
		public:
			Nop();
			void execute();
	};
}
