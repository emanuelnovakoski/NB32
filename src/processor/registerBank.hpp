#include "register.hpp"
#include "stateRegister.hpp"

#define REG_NUM 8

namespace NB32
{
	class RegisterBank
	{
		private:
			Register** registers;
			StateRegister* stRegister;
		public:
			RegisterBank();
			Register* getRegister(int index);
			StateRegister* getStateRegister();
	};
}
