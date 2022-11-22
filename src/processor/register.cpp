#include "register.hpp"

using namespace std;
namespace NB32
{
	Register::Register()
	{
		this->value = 0;
	}
	
	int Register::read()
	{
		return this->value;
	}
	
	void Register::write(int value)
	{
		this->value = value;
	}
	
	void Register::increment()
	{
		this->value++;
	}
	
	void Register::decrement()
	{
		this->value--;
	}
	
	char* Register::getAsString()
	{
		char* cValue = (char*) malloc(sizeof(char)*9);
		sprintf(cValue, "%08d", this->value);
		return cValue;
	}
}
