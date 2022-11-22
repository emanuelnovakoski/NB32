#include <cstdlib>
#include <cstring>
#include "registerBank.hpp"
#include <bitset>
#include <algorithm>

#define SIGNAL_BIT 2147483648
#define LEFTMOST_SIGNIFICATIVE_BIT 1073741824

namespace NB32
{
	class Alu
	{
		public:
			static int add(int a, int b, StateRegister* status);
			static int sub(int a, int b, StateRegister* status);
			static long mul(int a, int b, StateRegister* status);
			static int div(long a, int b, StateRegister* status);
			static int mod(long a, int b, StateRegister* status);
			static int bitAnd(int a, int b, StateRegister* status);
			static int bitOr(int a, int b, StateRegister* status);
			static int bitXor(int a, int b, StateRegister* status);
			static int asl(int a, int b, StateRegister* status);
			static unsigned int rot(unsigned int a, int b, StateRegister* status);
			
			static int inc(int a, StateRegister* status);
			static int dec(int a, StateRegister* status);
			static int neg(int a, StateRegister* status);
	};
}
