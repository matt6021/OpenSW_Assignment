PROJ_DIR := $(shell pwd)
SRC_DIR  := $(PROJ_DIR)/src
INC_DIR  := $(PROJ_DIR)/include
BIN_DIR  := $(PROJ_DIR)/bin
OBJ_DIR  := $(PROJ_DIR)/obj
LIB_DIR  := $(PROJ_DIR)/lib

CC      := gcc
AR      := ar
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)
ARFLAGS := rcs

LIB_NAME := libmybasic.a
LIB_PATH := $(LIB_DIR)/$(LIB_NAME)

SRCS_LIB := $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c
OBJS_LIB := $(SRCS_LIB:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_APP := $(SRC_DIR)/myapp.c
OBJS_APP := $(SRCS_APP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all basic clean run

all: $(BIN_DIR)/myapp

basic: $(LIB_PATH)

$(LIB_PATH): $(OBJS_LIB)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $(OBJS_LIB)

$(BIN_DIR)/myapp: basic $(OBJS_APP)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $(OBJS_APP) -L$(LIB_DIR) -lmybasic

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./bin/myapp

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
	@echo "Clean up."
