O_SOURCE=$(wildcard ./src/*.o)

NB32: memory alu register registerBank
	g++ $(O_SOURCE) src/nb32.cpp -o nb32 -lncurses
	
register:
	g++ -c src/register.cpp -o src/register.o

registerBank: register stateRegister
	g++ -c src/registerBank.cpp -o src/registerBank.o
	
stateRegister: 
	g++ -c src/stateRegister.cpp -o src/stateRegister.o
	
memory: 
	g++ -c src/memory.cpp -o src/memory.o

alu: 
	g++ -c src/alu.cpp -o src/alu.o
