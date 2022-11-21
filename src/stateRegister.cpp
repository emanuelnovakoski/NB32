#include "stateRegister.hpp"

namespace NB32
{
	StateRegister::StateRegister()
	{
		this->zero = false;
		this->negative = false;
		this->borrow = false;
		this->overflow = false;
	}
	
	bool StateRegister::isZero()
	{
		return this->zero;
	}
	
	bool StateRegister::isNegative()
	{
		return this->negative;
	}
	
	bool StateRegister::isOverflow()
	{
		return this->overflow;
	}
	
	bool StateRegister::isBorrow()
	{
		return this->borrow;
	}
	
	bool StateRegister::isCarry()
	{
		return this->carry;
	}
	
	void StateRegister::setZero(bool zero)
	{
		this->zero = zero;
	}
	void StateRegister::setNegative(bool negative)
	{
		this->negative = negative;
	}
	
	void StateRegister::setOverflow(bool overflow)
	{
		this->overflow = overflow;
	}
	
	void StateRegister::setBorrow(bool borrow)
	{
		this->borrow = borrow;
	}
	
	void StateRegister::setCarry(bool carry)
	{
		this->carry = carry;
	}
}
