# Generic makefile for a C project
# Written by Tom <tom@mail.org>
#
# specify the shell, in case the SHELL variable is not set or is not
# inherited from the environment
SHELL = /bin/bash

# set suffix list, to prevent confusion between different make programs
# line 17 clears an implied suffix list, and line 18 sets a new one
.SUFFIXES:
.SUFFIXES: .c .h .o

# project set up and directories
CC	= gcc
INCLDIR	= include/
BINDIR	= bin/
OBJDIR	= obj/
SRCDIR	= src/

# final executable name
_BIN	= a.out
BIN	= $(addprefix $(BINDIR), $(_BIN))

# files; here all object files will be stored in $(OBJDIR), with the
# same base names as corresponding c files from SRCDIR
SRC	= $(wildcard src/*.c)
_OBJS	= $(patsubst src/%.c, %.o, $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(_OBJS))

# compilation flags
CFLAGS = -Wall -std=c99 -pedantic -g -I$(INCLDIR)
OFLAGS =


# compile binary and object files
.PHONY: all
all: $(BIN) docs

$(BIN): $(BINDIR) $(OBJS)
	$(CC) $(OFLAGS) $(OBJS) -o $(BIN)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJS): $(OBJDIR) $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)


# generate docs with doxygen
# this is intended to be used with a Doxyfile that specifies LaTeX
# output; modify as required for different documentation formats
#
# DOCDIR and TEXDIR must match the appropriate directories specified in
# Doxyfile
DOCDIR = docs/
TEXDIR = latex/

.PHONY: docs docs-clean
docs: Doxyfile
	doxygen
#	generate PDF from LaTeX sources
	cd $(DOCDIR)$(TEXDIR) && $(MAKE)
	mv $(DOCDIR)$(TEXDIR)refman.pdf $(DOCDIR)

docs-clean:
	cd $(DOCDIR)$(TEXDIR) && $(MAKE) clean


# clean entire project directory
.PHONY: clean
clean:
	- rm -rf $(BINDIR) $(OBJDIR) $(DOCDIR)


# check code quality
.PHONY: cppcheck memcheck
cppcheck:
	cppcheck --enable=all --language=c --std=c99 --inconclusive \
	--suppress=missingInclude $(SRC) -i $(INCLDIR)

memcheck: all
	valgrind -v --show-leak-kinds=all --leak-check=full --track-origins=yes \
	./$(BIN)

# debugging make
print-% :
	@echo $* = $($*)
