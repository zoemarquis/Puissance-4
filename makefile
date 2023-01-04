CC := gcc
SRC_DIR ?= src
OBJ_DIR ?= obj
TEST_DIR ?= test
DEBUG ?= 1

ifeq '$ ( DEBUG ) ' '1 '
CFLAGS ?= -Wall -MMD -g
else
CFLAGS ?= -Wall -MMD -O3 -DNDEBUG
endif

LDFLAGS = -L./lib -lSDL2 -lcunit 

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS := $(OBJS : .o = .d )

SRC_TEST := $(wildcard $(TEST_DIR)/*.c )
OBJS_TEST := $(addprefix $(OBJ_DIR)/, $(SRC_TEST:.c=.o))
DEPS_TEST := $(OBJS_TEST:.o=.d)

TARGET ?= exec
TARGET_TEST ?= runTest

.PHONY: clean mrproper

all: createRep $(TARGET) docu

docu: doc/Doxyfile
	doxygen doc/Doxyfile

createRep:
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	@mkdir -p $(OBJ_DIR)/$(TEST_DIR)

$(TARGET): createRep $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(TARGET_TEST): clean createRep $(OBJS) $(OBJS_TEST)
	$(CC) -o $(TARGET_TEST) $(filter-out $(OBJ_DIR)/$(SRC_DIR)/main.o, $(OBJS)) $(OBJS_TEST) $(LDFLAGS)
	@./$(TARGET_TEST)

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) doc/html

mrproper : clean
	rm -f $(TARGET) $(TARGET_TEST)

-include $(DEPS) $(DEPS_TEST)