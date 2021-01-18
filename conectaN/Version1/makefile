AR= ar
CXX = g++
CXXFLAGS= -Wall -g -I $(INC)
LDFLAGS= -L $(LIB)/
LDLIBS= -ljuegos
INC= include
SRC= src
OBJ= obj
LIB= lib
BIN= bin

all: $(BIN)/conectaN

$(BIN)/conectaN:  $(OBJ)/matriz.o $(OBJ)/tablero.o $(OBJ)/jugador.o $(OBJ)/conectaN.o
	$(CXX) -o $(BIN)/conectaN $^

$(OBJ)/matriz.o: $(SRC)/matriz.cpp $(INC)/matriz.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/matriz.o $(SRC)/matriz.cpp

$(OBJ)/tablero.o: $(SRC)/tablero.cpp $(INC)/matriz.h $(INC)/tablero.h 
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/tablero.o $(SRC)/tablero.cpp

$(OBJ)/jugador.o: $(SRC)/jugador.cpp $(INC)/tablero.h $(INC)/jugador.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/jugador.o $(SRC)/jugador.cpp

$(OBJ)/conectaN.o: $(SRC)/conectaN.cpp $(INC)/tablero.h $(INC)/jugador.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/conectaN.o $(SRC)/conectaN.cpp

clean:
	echo "Limpiando..."
	rm  -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	rm -f $(BIN)/*
