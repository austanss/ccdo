SOURCE	= src
OUTPUT	= bin
INCLUDE = inc

CPPCODE = $(shell find $(SOURCE) -type f -name '*.cc')
OBJECTS	= $(patsubst $(SOURCE)/%.cc, $(OUTPUT)/%.cc.o, $(CPPCODE))

EXECUTE = ccdo
PROGRAM	= $(OUTPUT)/$(EXECUTE)

XMLINC 	= /usr/include/libxml2

CC 	= clang++
LD 	= clang++

CCFLAGS = \
-I$(SOURCE) \
-I$(INCLUDE) \
-I$(XMLINC) \
-std=c++17 \
-fpie \
-gdwarf \
-Werror \
-pedantic

LDFLAGS = \
-pie \
-lxml2

.DEFAULT-GOAL	= all
.PHONY			= clean install uninstall

all: $(PROGRAM)

$(OUTPUT)/%.cc.o: $(SOURCE)/%.cc
	@ echo "	compile $^"
	@ mkdir -p $(@D)
	@ $(CC) $(CCFLAGS) -c $^ -o $@

$(PROGRAM): $(OBJECTS)
	@ echo "	link $@ (1/1)"
	@ $(LD) $(LDFLAGS) $(OBJECTS) -o $(PROGRAM)

clean:
	@ rm -rf $(OUTPUT)

# define ARGS in the command line in order to add additional arguments
# ex: make run ARGS="build"
run: $(PROGRAM)
	@ echo "	executing $(PROGRAM)"
	@ echo "	-------"
	@ echo " "
	@ $(PROGRAM) $(ARGS)
	@ echo " "

INSTALL = /usr/local/bin

install: $(PROGRAM)
	@ cp $(PROGRAM) $(INSTALL)/$(EXECUTE)

uninstall:
	@ rm -f $(INSTALL)/$(EXECUTE)
