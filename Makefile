CXX       := g++

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := -lncurses
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

