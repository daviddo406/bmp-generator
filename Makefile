
CC		= clang++
CFLAGS 	= -std=c++20 -Wc++11-extensions -Ilib/EasyBMP_1  `pkg-config --cflags opencv4` -Iinclude -Iinclude/generator
LDFLAGS = `pkg-config --libs opencv4`

BIN_DIR = bin
OBJ_DIR = obj
EXEC 	= $(BIN_DIR)/my_program

OBJ_FILES = $(OBJ_DIR)/main.o $(OBJ_DIR)/easybmp.o $(OBJ_DIR)/stripes.o

all: $(EXEC)

$(EXEC): $(OBJ_FILES) $(BIN_DIR)
	$(CC) $(CFLAGS) -o bin/my_program $(OBJ_FILES) $(LDFLAGS)

$(OBJ_DIR)/main.o: src/main.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/main.cpp -o obj/main.o

$(OBJ_DIR)/easybmp.o: lib/EasyBMP_1/EasyBMP.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -c lib/EasyBMP_1/EasyBMP.cpp -o obj/easybmp.o

$(OBJ_DIR)/stripes.o: src/generator/stripes.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/generator/stripes.cpp -o obj/stripes.o



# Create directories
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: $(EXEC)
	./$(EXEC) 256 256

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: all run clean