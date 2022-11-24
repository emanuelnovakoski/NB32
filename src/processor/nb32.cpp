// TODO make this class instantiable
// TODO make a different program class
// TODO move auxiliary methods into an util file
#include "nb32.hpp"

using namespace std;
using namespace NB32;

void formatStringToMemoryVisual(char* str[], int length, int startIndex);

int main(int argc, char** argv)
{	
	

	Memory* ram = new Memory();
	RegisterBank* regBank = new RegisterBank();
	Memory* memory = new Memory();
	MemoryInterface* memInterface;

	if (argc == 2)
	{
		memory->loadMemoryFromFile(argv[1]);
	}
	
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	printw("Hello World !!!");	
	refresh();			
	
	try
	{
		memInterface = new MemoryInterface(memory);
	}
	catch (...)
	{
		delete memInterface;
	}
	

	
	getch();
	
	if (memInterface != NULL)
		memInterface->destroyScreen();
		

	endwin();
	
	// ALU test neg
	/*
	int a = -5003;
	cout << (Alu::neg(a, regBank->getStateRegister())) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	
	// ALU test dec
	/*
	int a = 1;
	cout << (Alu::dec(a, regBank->getStateRegister())) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	// ALU test inc
	/*
	int a = 2147483647;
	cout << (Alu::inc(a, regBank->getStateRegister())) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	
	// ALU test rot
	/*
	unsigned int a = 1073741824*2;
	int b = 1;
	cout << (Alu::rot(a, b, regBank->getStateRegister())) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	// ALU test asl
	/*
	int a = -1073741825;
	int b = 2;
	cout << Alu::asl(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	
	// ALU test bitwises
	/*
	int a = 13;
	int b = 7;
	cout << Alu::bitAnd(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	
	cout << endl;
	cout << Alu::bitOr(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	
	cout << endl;
	cout << Alu::bitXor(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	
	// ALU test mod
	/*long a = -13;
	int b = 10;
	cout << Alu::mod(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	
	cout << endl;
	
	a = 4;
	b = 0;
	cout << Alu::div(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	
	// ALU test div
	/*
	long a = 0;
	int b = 10;
	cout << Alu::div(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	
	// ALU test mul
	/*
	int a = 0;
	int b = -2147483647;
	cout << Alu::mul(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isNegative() << endl;
	cout << regBank->getStateRegister()->isZero() << endl;
	*/
	// ALU test sub
	/*
	int a = 1;
	int b = 2147483647;
	cout << Alu::sub(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	
	a = 2147483647;
	b = -2;	
	cout << Alu::sub(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	
	a = 2147483647;
	b = 2;	
	cout << Alu::sub(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	
	a = -100;
	b = 2;	
	cout << Alu::sub(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isBorrow() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	*/
	// ALU test add
	/*
	int a = 1;
	int b = -1;
	cout << Alu::add(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	
	a = 2147483647;
	b = 1;
	cout << Alu::add(a, b, regBank->getStateRegister()) << endl;
	cout << regBank->getStateRegister()->isCarry() << endl;
	cout << regBank->getStateRegister()->isOverflow() << endl;
	*/
	
	// StateRegister test
	/*
	cout << stReg->isOverflow() << endl;
	stReg->setOverflow(true);
	cout << stReg->isOverflow() << endl;
	
	cout << stReg->isCarry() << endl;
	stReg->setCarry(true);
	cout << stReg->isCarry() << endl;
	*/

	// Register test
	/* 
	cout << regA->getAsString() << endl;
	
	regA->write(100);
	
	cout << regA->getAsString() << endl;
	
	regA->increment();
	
	printf("%08d\n", regA->read());
	
	regA->decrement();
	regA->decrement();
	
	cout << regA->getAsString() << endl;
	*/


	// Memory test
	
	/*
	char test[2][9] = {"00010001", "00110011"};
	
	//ram->loadMemoryFromFile("mem.txt");
	cout << "HERE" << endl;
	
	
	char* read[20];
	
	ram->store(11, 2, test);
	ram->read(read, 0, 20);
	
	formatStringToMemoryVisual(read, 20, 0);
	
	
	cout << "\n";
	
	ram->dumpMemoryToFile("dump.txt");
	*/
	return 0;
}

void formatStringToMemoryVisual(char* buffer[], int length, int startIndex)
{
	for (int i=0; i<length; i++)
	{
		printf("%010x : ", startIndex+i);
		cout << buffer[i] << endl;
	}

}
