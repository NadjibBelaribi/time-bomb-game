CC=g++
CFLAGS=-Wall -Wextra -Werror
SRC_DIR=src/
HDS_DIR=headers/
OBJ_DIR=obj/


$(OBJ_DIR)GSocket.o: $(SRC_DIR)GSocket.cpp $(HDS_DIR)GSocket.h ../kernel/$(HDS_DIR)Game.h
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv GSocket.o $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
