CC=g++
CFLAGS=-Wall -Wextra -Werror -pthread
EXEC_LOCAL=local
EXEC_NETWORK=network
SRC_DIR=src/
HDS_DIR=headers/
OBJ_DIR=obj/

.PHONY: all
all: $(EXEC_LOCAL) $(EXEC_NETWORK)

$(EXEC_LOCAL): $(OBJ_DIR)$(EXEC_LOCAL).o ../kernel/$(OBJ_DIR)libkernel.a
	$(CC) $(CFLAGS) -o $(EXEC_LOCAL) $< -lkernel -L ../kernel/$(OBJ_DIR)

$(OBJ_DIR)$(EXEC_LOCAL).o: $(SRC_DIR)$(EXEC_LOCAL).cpp
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv $(EXEC_LOCAL).o $(OBJ_DIR)

$(EXEC_NETWORK): $(OBJ_DIR)$(EXEC_NETWORK).o ../network/$(OBJ_DIR)libnetwork.a
	$(CC) $(CFLAGS) -o $(EXEC_NETWORK) $< -lnetwork -L ../network/$(OBJ_DIR)

$(OBJ_DIR)$(EXEC_NETWORK).o: $(SRC_DIR)$(EXEC_NETWORK).cpp
	$(CC) $(CFLAGS) -c $<
	mkdir -p $(OBJ_DIR)
	mv $(EXEC_NETWORK).o $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(EXEC_LOCAL) $(EXEC_NETWORK)
