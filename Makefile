define HEADER 
 _/_/_/_/_/_/_/_/_/_/_/
|.                    |/ 
|     _____  _____    |/ 
|    |      |         |/ 
|    |_____ |_____    |/ 
|    |      |         |/ 
|    |_____ |_____    |/ 
|                     |/ 
|_____________________|/ SIOCookie

Coded by El_isra. Idea from uyjulian

endef
export HEADER

EE_LIB = libsiocookie.a
EE_OBJS = src/SIOCookie.o
EE_CFLAGS += -fdata-sections -ffunction-sections
EE_LDFLAGS += -Wl,--gc-sections
EE_INCS += -I./include

ifeq ($(DEBUG), 1)
  EE_CFLAGS += -DDEBUG -O0 -g
else 
  EE_CFLAGS += -Os
  EE_LDFLAGS += -s
endif

all: $(EE_LIB)
	@echo "$$HEADER"

clean:
	rm -rf $(EE_OBJS) $(EE_LIB)


install: all
	mkdir -p $(DESTDIR)$(PS2SDK)/ports/include/
	mkdir -p $(DESTDIR)$(PS2SDK)/ports/lib
	cp -f $(EE_LIB) $(DESTDIR)$(PS2SDK)/ports/lib
	cp -f include/*.h $(DESTDIR)$(PS2SDK)/ports/include/

rebuild: clean all

# Include makefiles
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
