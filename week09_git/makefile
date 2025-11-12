# ========== 경로 ==========
PROJ := $(shell pwd)
SRC  := $(PROJ)/src
INC  := $(PROJ)/include
OBJ  := $(PROJ)/obj
LIBD := $(PROJ)/lib
BIND := $(PROJ)/bin

# ========== 컴파일러/옵션 ==========
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -I$(INC)
PIC     := -fPIC

# ========== 라이브러리 이름 ==========
LIBNAME := libmyops
SONAME  := $(LIBNAME).so.1
REAL    := $(LIBNAME).so.1.0

# ========== 연산 소스(예시와 같은 이름 6개) ==========
OPS     := myadd mysub mymul mydiv mypow mymod
OPS_SRC := $(addprefix $(SRC)/,$(addsuffix .c,$(OPS)))
OPS_OBJ := $(addprefix $(OBJ)/,$(addsuffix .o,$(OPS)))

APP_SRC := $(SRC)/myapp.c
APP_OBJ := $(OBJ)/myapp.o
APP_BIN := $(BIND)/myapp

.PHONY: all clean lib

all: $(APP_BIN)

# 실행 파일
$(APP_BIN): $(APP_OBJ) $(LIBD)/$(REAL) | $(BIND)
	$(CC) -o $@ $(APP_OBJ) -L$(LIBD) -lmyops -lm -Wl,-rpath,$(LIBD)

# 공유 라이브러리
lib: $(LIBD)/$(REAL)

$(LIBD)/$(REAL): $(OPS_OBJ) | $(LIBD)
	$(CC) -shared -Wl,-soname,$(SONAME) -o $@ $(OPS_OBJ) -lm
	ln -sf $(REAL)  $(LIBD)/$(SONAME)
	ln -sf $(SONAME) $(LIBD)/$(LIBNAME).so

# 오브젝트 규칙(연산 소스에는 -fPIC)
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@if echo "$(OPS)" | grep -qw "$(basename $(notdir $<))"; then \
		$(CC) $(CFLAGS) $(PIC) -c $< -o $@ ; \
	else \
		$(CC) $(CFLAGS) -c $< -o $@ ; \
	fi

$(OBJ) $(LIBD) $(BIND):
	mkdir -p $@

clean:
	rm -rf $(OBJ)/* $(LIBD)/* $(BIND)/*
