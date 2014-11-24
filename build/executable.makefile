TARGET_OBJECT = $(BIN)/$(TARGET)

include $(BUILD)/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -o $@
	
clean: 
	@rm -f obj/*
	@rm -f gcov/*
	@rm -f $(BIN)/$(TARGET) >/dev/null