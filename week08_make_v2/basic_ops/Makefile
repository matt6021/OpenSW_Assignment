.PHONY: all clean

# 모듈 내부 경로 (상대경로)
SRC_DIR := src
OBJ_DIR := obj

# 루트(상위) 경로 (상대경로)
TOP     := ..
INC_DIR := $(TOP)/include
LIB_DIR := $(TOP)/lib

CC := gcc
AR := ar
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)
ARFLAGS := rcs

LIB  := $(LIB_DIR)/libmybasic.a
SRCS := $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c
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
