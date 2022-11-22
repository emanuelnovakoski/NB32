#include "alu.hpp"

using namespace std;
namespace NB32
{
	int Alu::add(int a, int b, StateRegister* status)
	{
		int r = a+b;
		unsigned int ru = (unsigned int)a+b;
		
		// set overflow
		if (((a>0)&&(b>0)&&(r<0)) || ((a<0)&&(b<0)&&(r>0)))
		{
			status->setOverflow(true);
		}
		else
		{
			status->setOverflow(false);
		}
		
		// set carry
		if (ru < (unsigned int) a)
		{
			status->setCarry(true);
		}
		else
		{
			status->setCarry(false);
		}
		
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		
		return r;
		
	}
	int Alu::sub(int a, int b, StateRegister* status)
	{
		/*int r = a - b;
		unsigned int au = (unsigned int) a;
		unsigned int bu = (unsigned int) b;
		// set overflow
		if (((a>0)&&(b<0)&&(r<0)) || ((a<0)&&(b>9)&&(r>0)))
		{
			status->setOverflow(true);
		}
		else
		{
			status->setOverflow(false);
		}
		
		// set borrow
		if (au < bu)
		{
			status->setBorrow(true);
		}
		else
		{
			status->setBorrow(false);
		}
		return r;
		*/
		bool pCarry = status->isCarry();
		int r = Alu::add(a, -b, status);
		status->setBorrow(!status->isCarry());
		status->setCarry(pCarry);
		return r;
		
	 }
	 
	long Alu::mul(int a, int b, StateRegister* status)
	{	 
		long r = (long) a*b;
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		return r;
	}
	
	int Alu::div(long a, int b, StateRegister* status)
	{
		int r = (b==0) ? 0 : a/b;
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		return r;
	}
	
	int Alu::mod(long a, int b, StateRegister* status)
	{
		int r = (b==0) ? 0 : a%b;
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		return r;
	}
	
	int Alu::bitAnd(int a, int b, StateRegister* status)
	{
		int r = (long) a&b;
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		return r;
	}
	
	int Alu::bitOr(int a, int b, StateRegister* status)
	{
		int r = (long) a|b;
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		return r;
	}
	
	int Alu::bitXor(int a, int b, StateRegister* status)
	{
		int r = (long) a^b;
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		return r;
	}
	
	int Alu::asl(int a, int b, StateRegister* status)
	{
		int signal = a & SIGNAL_BIT;
		
		int r = a << b;
		r |= signal;
		
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		
		return r;
	}
	
	
	// https://www.geeksforgeeks.org/left-rotation-right-rotation-string-2/ gave some help
	void leftrotate(string &s, int d)
	{
		reverse(s.begin(), s.begin()+d);
		reverse(s.begin()+d, s.end());
		reverse(s.begin(), s.end());
	}
	 
	// In-place rotates s towards right by d
	void rightrotate(string &s, int d)
	{
	   leftrotate(s, s.length()-d);
	}
	
	unsigned int Alu::rot(unsigned int a, int b, StateRegister* status)
	{
	 	
	 	unsigned int n = b % 32;
	 	
	 	std::string word = bitset<32>(a).to_string();
	 	
	 	leftrotate(word, n);
	 	
	 	
	 	unsigned int r = (unsigned int)stoul(word, nullptr, 2);
	 	
	 	if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}

		
		return r;
	}
	
	int Alu::inc(int a, StateRegister* status)
	{
		int r = a+1;
		unsigned int ru = (unsigned int)a+1;
		
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		
		// set overflow
		if ((a>0)&&(r<0))
		{
			status->setOverflow(true);
		}
		else
		{
			status->setOverflow(false);
		}
		
		// set carry
		if (ru < (unsigned int) a)
		{
			status->setCarry(true);
		}
		else
		{
			status->setCarry(false);
		}
		
		return r;
	}
	
	
	int Alu::dec(int a, StateRegister* status)
	{
		int r = a-1;
		unsigned int ru = (unsigned int)a-1;
		
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		
		// set overflow
		if ((a<0)&&(r>0))
		{
			status->setOverflow(true);
		}
		else
		{
			status->setOverflow(false);
		}
		
		// set carry
		if (ru > (unsigned int) a)
		{
			status->setBorrow(true);
		}
		else
		{
			status->setBorrow(false);
		}
		
		return r;
	}
	
	int Alu::neg(int a, StateRegister* status)
	{
		int r = ~a;
		
		if (r == 0)
		{
			status->setZero(true);
		}
		else
		{
			status->setZero(false);
		}
		if (r < 0)
		{
			status->setNegative(true);
		}
		else
		{
			status->setNegative(false);
		}
		
		return r;
	}
}
