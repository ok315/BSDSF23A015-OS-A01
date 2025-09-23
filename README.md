# BSDSF23A015-OS-A01

This repository contains my Operating Systems assignment 1, where I create a core C utilities library named **libmyutils**. The project demonstrates modular programming, static and dynamic libraries, build automation with Makefile, documentation, and version control using Git.

# The project demonstrates:-

Modular programming
Multi-file projects using Makefile
Static libraries (.a)
Dynamic/shared libraries (.so)
Build automation and dependency management
Documentation and analysis in REPORT.md
Version control and Git workflow (branching, merging, tagging, and releases)

## Project Structure

src/      - Source code files
include/  - Header files
lib/      - Compiled libraries (static .a and dynamic .so)
bin/      - Executables
obj/      - Object files
REPORT.md - Analysis and reflections

# Implemented Features

-> Project Scaffolding & Control
-> Organized directories, created initial Makefile, and set up Git workflow.
-> Multi-file Project Using Makefile
-> Compiled multiple .c files into object files and linked them into executables.
-> Creating and Using Static Library
-> Built libmyutils.a and linked it with client_static executable.
-> Creating and Using Dynamic Library
-> Built libmyutils.so with -fPIC.
-> Linked it with client_dynamic executable.
-> Demonstrated dynamic linking, LD_LIBRARY_PATH, and verification using ldd.
