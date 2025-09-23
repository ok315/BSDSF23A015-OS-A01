# ===========================
# File: Makefile (root level)
# ===========================

.PHONY: all clean

# Default target: delegate build to src/
all:
	$(MAKE) -C src

# Clean target: delegate clean to src/
clean:
	$(MAKE) -C src clean

install:
	sudo cp bin/client /usr/local/bin/
	sudo cp -r man/man3 /usr/local/share/man/
	sudo mandb
