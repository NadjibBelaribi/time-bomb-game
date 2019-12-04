CC=g++ -g
CFLAGS=-Wall -Wextra -Werror
SRC_DIR=src/
HDS_DIR=headers/
OBJ_DIR=obj/

$(OBJ_DIR)libkernel.a: $(OBJ_DIR)Player.o $(OBJ_DIR)Game.o $(OBJ_DIR)Card.o
	ar crs libkernel.a $^
	mkdir -p $(OBJ_DIR)
	mv libkernel.a $(OBJ_DIR)

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
	rm -rf $(OBJ_DIR)
