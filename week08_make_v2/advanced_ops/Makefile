.PHONY: all clean

SRC_DIR := src
OBJ_DIR := obj

TOP     := ..
INC_DIR := $(TOP)/include
LIB_DIR := $(TOP)/lib

CC := gcc
AR := ar
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)
ARFLAGS := rcs

LIB  := $(LIB_DIR)/libmyadvanced.a
SRCS := $(SRC_DIR)/mymod.c $(SRC_DIR)/mypow.c
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIB)

$(LIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
