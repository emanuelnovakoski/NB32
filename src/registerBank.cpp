#include "registerBank.hpp"

namespace NB32
{

	RegisterBank::RegisterBank()
	{
		registers = (Register**) malloc(sizeof(Register*)*REG_NUM);
		for (int i=0; i<REG_NUM; i++)
		{
			registers[i] = new Register();
		}
		
		stRegister = new StateRegister();
	}
	
	Register* RegisterBank::getRegister(int index)
	{
		return registers[index];
	}
	
	StateRegister* RegisterBank::getStateRegister()
	{
		return stRegister;
	}
}
