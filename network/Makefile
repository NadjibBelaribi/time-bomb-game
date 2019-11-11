CC=g++
CFLAGS=-Wall -Wextra -Werror
SRC_DIR=src/
HDS_DIR=headers/
OBJ_DIR=obj/

.PHONY: all
all: $(OBJ_DIR)GSocket.o $(OBJ_DIR)Host.o $(OBJ_DIR)Client.o

$(OBJ_DIR)GSocket.o: $(SRC_DIR)GSocket.cpp $(HDS_DIR)GSocket.h ../kernel/$(HDS_DIR)Game.h
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv GSocket.o $(OBJ_DIR)

$(OBJ_DIR)Host.o: $(SRC_DIR)Host.cpp $(HDS_DIR)Host.h $(HDS_DIR)GSocket.h
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv Host.o $(OBJ_DIR)

$(OBJ_DIR)Client.o: $(SRC_DIR)Client.cpp $(HDS_DIR)Client.h $(HDS_DIR)GSocket.h
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv Client.o $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
