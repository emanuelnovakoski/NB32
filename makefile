O_SOURCE=$(wildcard ./src/processor/*.o)
O_INTERFACE_SOURCE=$(wildcard ./src/interface/*.o)
SRC_DIR=src/processor
INTERFACE_DIR=src/interface

NB32: memory alu register registerBank memoryInterface
	g++ $(SRC_DIR)/nb32.cpp $(O_SOURCE) $(O_INTERFACE_SOURCE) -o nb32 -lncurses
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

memoryInterface: memory
	g++ -c $(INTERFACE_DIR)/memoryInterface.cpp -o $(SRC_DIR)/memoryInterface.o
	
clean:
	rm $(O_SOURCE) $(O_INTERFACE_SOURCE) nb32
