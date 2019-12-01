CC=g++
CFLAGS=-Wall -Wextra -Werror -pthread
SRC_DIR=src/
HDS_DIR=headers/
OBJ_DIR=obj/

$(OBJ_DIR)libnetwork.a: $(OBJ_DIR)GSocket.o $(OBJ_DIR)Host.o $(OBJ_DIR)Client.o ../kernel/$(OBJ_DIR)Game.o ../kernel/$(OBJ_DIR)Player.o ../kernel/$(OBJ_DIR)Card.o
	ar crs libnetwork.a $^
	mkdir -p $(OBJ_DIR)
	mv libnetwork.a $(OBJ_DIR)

$(OBJ_DIR)GSocket.o: $(SRC_DIR)GSocket.cpp $(HDS_DIR)GSocket.h
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
