.PHONY: clean mrproper all

AR = ar
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g -I $(INC)
LDFLAGS = -L$(LIB)
LDLIBS = -lformas
INC = ./include
SRC = ./src
OBJ = ./obj
LIB = ./lib
BIN = ./bin

all : central area longitud delimitar
	
central : $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/central $(OBJ)/central.o $(LDFLAGS) $(LDLIBS)

area : $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/area $(OBJ)/area.o $(LDFLAGS) $(LDLIBS)

longitud : $(OBJ)/longitud.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/longitud $(OBJ)/longitud.o $(LDFLAGS) $(LDLIBS)

delimitar : $(OBJ)/delimitar.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/delimitar $(OBJ)/delimitar.o $(LDFLAGS) $(LDLIBS)

obj/central.o : $(INC)/circulo.h $(INC)/punto.h $(SRC)/central.cpp 
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp

obj/area.o : $(SRC)/area.cpp $(INC)/circulo.h $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp

obj/longitud.o : $(SRC)/longitud.cpp $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/longitud.o $(SRC)/longitud.cpp

obj/delimitar.o : $(INC)/rectangulo.h $(INC)/punto.h $(SRC)/delimitar.cpp 
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/delimitar.o $(SRC)/delimitar.cpp

obj/punto.o : $(SRC)/punto.cpp $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp

obj/circulo.o : $(SRC)/circulo.cpp $(INC)/circulo.h $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp

obj/rectangulo.o : $(INC)/rectangulo.h $(INC)/punto.h $(SRC)/rectangulo.cpp 
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/rectangulo.o $(SRC)/circulo.cpp

lib/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o

clean:
	echo "Limpiando ..."
	-rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	-rm $(BIN)/*
