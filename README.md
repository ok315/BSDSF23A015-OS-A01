# BSDSF23A015-OS-A01

This repository contains Operating Systems Assignment 1, where I implemented a core C utilities library named libmyutils. The project demonstrates modular programming, static and dynamic libraries, build automation using Makefile, documentation, and version control with Git.

# Features Implemented

Project Scaffolding & Version Control
Organized project directories (src/, include/, lib/, bin/, obj/)
Initialized Git repository, created branches for each feature, committed changes, and maintained a clean history.
Multi-file Project Using Makefile
Compiled multiple source files into object files.
Linked object files to generate the executable client.
Used macros and multi-target Makefiles for professional build automation.
Static Library (libmyutils.a)
Bundled utility functions into a static library.
Linked it with the executable client_static.
Verified contents with ar, nm, and readelf.
Dynamic Library (libmyutils.so)
Built a position-independent shared library using -fPIC.
Linked it with the executable client_dynamic.
Demonstrated dynamic linking, used LD_LIBRARY_PATH, and verified with ldd.
Documentation & Man Pages
Created standard Linux man pages for the client and library functions.
Installed executable and man pages with make install.
Verified access system-wide using man <function>.
Reporting & Analysis
Answered all assignment questions in REPORT.md.
Analyzed build processes, library contents, and linking differences.

# The project demonstrates:-

Modular programming
Multi-file projects using Makefile
Static libraries (.a)
Dynamic/shared libraries (.so)
Build automation and dependency management
Documentation and analysis in REPORT.md
Version control and Git workflow (branching, merging, tagging, and releases)

# Project Structure

src/      - Source code files
include/  - Header files
lib/      - Compiled libraries (static .a and dynamic .so)
bin/      - Executables
obj/      - Object files
REPORT.md - Analysis and reflections

# How to Build and Run

1. Build all executables and libraries --
make

2. Run static client
./bin/client_static

3. Run dynamic client
export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
./bin/client_dynamic

4. Install executable and man pages system-wide
sudo make install
client         # run from anywhere
man mycat      # view man page

# Git Workflow

Separate branches for each feature: multifile-build, static-build, dynamic-build, manpages.
Used annotated tags for versioning:
  -v0.1.1-multifile
  -v0.2.1-static
  -v0.3.1-dynamic
  -v0.4.1-final
Releases created on GitHub for each milestone with attached binaries and libraries.

# Key Tools & Concepts Demonstrated

-> Modular programming in C
-> Makefile automation and multi-target builds
-> Static vs dynamic linking
-> Position-independent code (-fPIC)
-> Library inspection: ar, nm, readelf, ldd
-> Linux documentation (man pages)
-> Version control and Git workflow

# Acknowledgements
- Instructor: Dr. Muhammad Arif Butt, PhD
- Linux and C programming resources for Makefile, libraries, and man pages

# Future Improvements
- Extend the library with more utility functions
- Add unit tests for all functions
- Support cross-platform builds
- Improve documentation with examples and screenshots

# License
This project is for educational purposes.
