#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace NB32
{
	class Register
	{
		private:
			int value;
		public:
			Register();
			int read();
			void write(int value);
			void increment();
			void decrement();
			char* getAsString();
	};
}
