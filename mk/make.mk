SRC_FILE = $(foreach tmp,$(SRC_DIR),$(wildcard $(tmp)/*.c))
OBJ_FILE = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILE)))

$(EXE_FILE):$(OBJ_FILE)
	$(CC) $(OBJ_FILE) -o $(EXE_DIR)/$@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm -rf $(OBJ_FILE) $(EXE_FILE)
