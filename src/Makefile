# src/Makefile - builds lib/libmyutils.a and bin/client_static

.PHONY: all clean

# Tools
CC      := gcc
AR      := ar
RANLIB  := ranlib
CFLAGS  := -Wall -Wextra -I../include

# Directories
SRCDIR  := .
OBJDIR  := ../obj
BINDIR  := ../bin
LIBDIR  := ../lib

# Sources
SRCS     := $(wildcard $(SRCDIR)/*.c)
LIB_SRCS := $(filter-out $(SRCDIR)/main.c, $(SRCS))

# Objects
LIB_OBJS  := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(LIB_SRCS))
MAIN_OBJ  := $(OBJDIR)/main.o

# Targets
LIB     := $(LIBDIR)/libmyutils.a
TARGET  := $(BINDIR)/client_static

# Default build
all: $(TARGET)

# Link final executable
$(TARGET): $(MAIN_OBJ) $(LIB) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(LIB)

# Build static library
$(LIB): $(LIB_OBJS) | $(LIBDIR)
	$(AR) rcs $@ $^
	-$(RANLIB) $@

# Compile .c -> .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure directories exist
$(OBJDIR) $(LIBDIR) $(BINDIR):
	mkdir -p $@

# Clean build artifacts
clean:
	rm -f $(OBJDIR)/*.o $(LIB) $(TARGET)
