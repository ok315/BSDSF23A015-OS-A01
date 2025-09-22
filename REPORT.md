# Assignment 1 - Core C Utilities Library

## Project Setup

- Created a GitHub repository with the required naming convention.
- Initialized project folders (`src`, `include`, `lib`, `bin`, `obj`) to organize code and build artifacts.
- Set up version control with Git and pushed initial commits.
- Added placeholder `.gitkeep` files to track empty directories.

## Next Steps

- Implement string and file utility functions in C.
- Write a Makefile to automate building the library and main program.
- Document functions using Linux man pages.
- Explore static and dynamic linking.
- Analyze binaries using Linux tools.
- Maintain a clean Git workflow with branching and tagging.

# Assignment 1 - Core C Utilities Library

## Objective
The objective of this assignment is to design a small **Core C Utilities Library** that provides string and file utility functions.  
The project also focuses on practicing **Linux development tools** such as `make`, static & dynamic linking, Git workflow, and binary analysis.

---

## Project Setup
- Created a GitHub repository with the required naming convention.
- Initialized project folders to organize code and build artifacts:
  - `src` → source files  
  - `include` → header files  
  - `lib` → static and dynamic libraries  
  - `bin` → final executables  
  - `obj` → object files  
- Set up version control with Git and pushed initial commits.
- Added placeholder `.gitkeep` files to track empty directories.

---

## Implementation

### String Utility Functions
- Implemented `my_strlen(const char *str)` to calculate the length of a string.  
- Implemented `my_strcpy(char *dest, const char *src)` to copy one string into another.  
- Tested functions against standard library equivalents (`strlen`, `strcpy`).  
- Files:
  - `src/string_utils.c`
  - `include/string_utils.h`

### File Utility Functions
- Implemented `my_fsize(const char *filename)` to get the size of a file.  
- Implemented `my_fexists(const char *filename)` to check if a file exists.  
- Files:
  - `src/file_utils.c`
  - `include/file_utils.h`

---

## Compilation & Execution
- Created a **Makefile** to automate building.  
- Commands used:
  ```bash
  make clean && make
  ./bin/main

---

## Report Questions

### 1. Explain the linking rule in this part's Makefile:  
`$(TARGET): $(OBJECTS)`  
This rule means that the final executable (`$(TARGET)`) depends on all the object files (`$(OBJECTS)`).  
- The compiler (usually `gcc`) will link all these object files together to produce the executable.  
- This is **direct linking**, because we are passing compiled `.o` files directly.  

In contrast, a Makefile rule that links against a **library** (e.g., `-lmylib`) does not require all object files explicitly. Instead, the linker searches for needed symbols inside the specified library. Example:  
```make
$(TARGET): main.o
    gcc main.o -Llib -lmylib -o $(TARGET)

### 2. What is a git tag and why is it useful in a project?

A git tag marks a specific commit as important, usually representing a release version.

Tags make it easy to return to or reference that exact point in history.

They are especially useful for versioning software (e.g., v1.0.0).

Difference:

Lightweight tag → just a pointer to a commit (like a branch that doesn’t move).

Annotated tag → stored as a full Git object, including tagger name, date, and message. It’s recommended for releases because it contains metadata.

### 3. What is the purpose of creating a "Release" on GitHub?

A GitHub Release is a packaged version of the project tied to a tag.

It provides an easy way for others to download stable versions without browsing commits.

Maintains changelogs and descriptions for each version.

Significance of attaching binaries:

Users who don’t want to compile the source can directly download the ready-to-run executable (e.g., your bin/client).

It improves accessibility and distributes prebuilt artifacts for different platforms.

### 1. Compare the Makefile from Part 2 and Part 3

-> Part 2 (Multifile Build) Makefile:

Compiled all source files together directly into a single executable.

Variables: SOURCES, OBJECTS, TARGET.

Linking rule: all .o files linked directly into the executable.

No library was created; main program and utility functions were all compiled together.

-> Part 3 (Static Library Build) Makefile:

Utility functions are compiled into a static library (libmyutils.a).

Variables added: LIB_SRCS, LIB_OBJS, LIB.

Linking rule: main object (main.o) is linked with the static library to produce the executable.

Separate compilation allows for better modularity, reusability, and faster compilation when only library code changes.

Key differences that enable the static library:

Creation of LIB_OBJS for all non-main source files.

$(LIB) target using ar rcs to bundle object files into libmyutils.a.

The executable links main.o with the static library instead of all objects individually.

New directory lib/ for storing the library.

### 2. Purpose of the ar command and ranlib

ar (archiver) is used to create, modify, and extract from archive files. In this context, it bundles multiple object files into a single static library (.a).

ranlib generates an index of symbols in the archive, which is used by the linker to quickly locate functions in the library.

Using ranlib immediately after ar ensures that the static library is ready for linking and avoids “undefined reference” errors during compilation.

### 3. Running nm on client_static

nm bin/client_static lists all symbols in the executable.

Symbols like mystrlen, mystrcpy etc. are present, indicating that the static library's functions are fully included in the final executable.

Implication: In static linking, all the required functions from the library are copied into the executable at compile/link time. The final binary contains everything it needs to run independently of the library files.
