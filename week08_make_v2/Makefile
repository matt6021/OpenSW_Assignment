.PHONY: all basic_ops advanced_ops clean
PROJ_DIR := $(shell pwd)
SRC_DIR  := $(PROJ_DIR)/src
INC_DIR  := $(PROJ_DIR)/include
BIN_DIR  := $(PROJ_DIR)/bin
OBJ_DIR  := $(PROJ_DIR)/obj
LIB_DIR  := $(PROJ_DIR)/lib
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)
LDFLAGS := -L$(LIB_DIR) -lmybasic -lmyadvanced
STATIC_LIBS := $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

all: basic_ops advanced_ops $(BIN_DIR)/myapp

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(STATIC_LIBS)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $(OBJ_DIR)/myapp.o $(LDFLAGS)

$(OBJ_DIR)/myapp.o: $(SRC_DIR)/myapp.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
