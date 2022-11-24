#include "specialInst.hpp"

namespace NB32
{
	class Hlt : public SpecialInst
	{
		public:
			Hlt();
			int execute();
	};
}
