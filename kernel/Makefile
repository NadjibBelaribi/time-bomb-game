CC=g++
CFLAGS=-Wall -Wextra -Werror
EXEC=test
SRC_DIR=src/
HDS_DIR=headers/
OBJ_DIR=obj/

$(EXEC): $(OBJ_DIR)$(EXEC).o $(OBJ_DIR)Player.o $(OBJ_DIR)Game.o $(OBJ_DIR)Card.o
	$(CC) $(CFLAGS) -o $(EXEC) $^

$(OBJ_DIR)$(EXEC).o: $(SRC_DIR)$(EXEC).cpp
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv $(EXEC).o $(OBJ_DIR)

$(OBJ_DIR)Game.o: $(SRC_DIR)Game.cpp $(HDS_DIR)Game.h $(HDS_DIR)Player.h $(HDS_DIR)Card.h
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv Game.o $(OBJ_DIR)

$(OBJ_DIR)Player.o: $(SRC_DIR)Player.cpp $(HDS_DIR)Player.h $(HDS_DIR)Card.h
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv Player.o $(OBJ_DIR)

$(OBJ_DIR)Card.o: $(SRC_DIR)Card.cpp $(HDS_DIR)Card.h
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv Card.o $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

