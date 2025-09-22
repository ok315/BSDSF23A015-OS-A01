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
