O_SOURCE=$(wildcard ./src/processor/*.o)
O_INTERFACE_SOURCE=$(wildcard ./src/interface/*.o)
O_INTERPRETER_SOURCE=$(wildcard ./src/interpreter/*.o)
SRC_DIR=src/processor
INTERFACE_DIR=src/interface
INTERPRETER_DIR=src/interpreter

NB32: memory alu register registerBank memoryInterface 
	g++ $(SRC_DIR)/nb32.cpp $(O_SOURCE) $(O_INTERFACE_SOURCE) $(O_INTERPRETER_SOURCE) -o nb32 -lncurses
	rm $(O_SOURCE) $(O_INTERFACE_SOURCE)
	
register:
	g++ -c $(SRC_DIR)/register.cpp -o $(SRC_DIR)/register.o

registerBank: register stateRegister
	g++ -c $(SRC_DIR)/registerBank.cpp -o $(SRC_DIR)/registerBank.o
	
stateRegister: 
	g++ -c $(SRC_DIR)/stateRegister.cpp -o $(SRC_DIR)/stateRegister.o
	
memory: 
	g++ -c $(SRC_DIR)/memory.cpp -o $(SRC_DIR)/memory.o

alu: 
	g++ -c $(SRC_DIR)/alu.cpp -o $(SRC_DIR)/alu.o

memoryInterface: memory interpreter 
	g++ -c $(INTERFACE_DIR)/memoryInterface.cpp -o $(SRC_DIR)/memoryInterface.o

specialInst: nop hlt
	g++ -c $(INTERPRETER_DIR)/specialInst.cpp -o $(INTERPRETER_DIR)/specialInst.o

instruction: 
	g++ -c $(INTERPRETER_DIR)/instruction.cpp -o $(INTERPRETER_DIR)/instruction.o
	
interpreter: specialInst instruction
	g++ -c $(INTERPRETER_DIR)/interpreter.cpp -o $(INTERPRETER_DIR)/interpreter.o
	
nop:
	g++ -c $(INTERPRETER_DIR)/nop.cpp -o $(INTERPRETER_DIR)/nop.o

hlt:
	g++ -c $(INTERPRETER_DIR)/hlt.cpp -o $(INTERPRETER_DIR)/hlt.o

clean:
	rm $(O_SOURCE) $(O_INTERFACE_SOURCE) $(O_INTERPRETER_SOURCE) nb32
