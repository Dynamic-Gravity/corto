TARGET_OBJECT = $(BUILDHOME)/generator/bin/$(TARGET)
LIBPATH += $(BUILDHOME)/generator/bin

include $(BUILD)/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@
	
clean: 
	@rm -f obj/$(PPREFIX)/*
	@rm -f gcov/*
	@rm -f $(BIN)/$(TARGET) >/dev/null