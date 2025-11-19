# Guide to Compiling This Project

This guide explains how to compile the project, which is split across multiple `.c` and `.h` files. Understanding this is key to working with many C projects.

## The "Undefined Reference" Error

A common issue when compiling a C project with multiple files is an error like `undefined reference to function '...'`. This typically happens if you only compile the file containing `main()` without also including the other source files where functions are defined.

This error occurs because the C build process involves two key stages: **Compilation** and **Linking**.

## The Compilation Process Explained

### Stage 1: Compilation

*   **What it does:** The compiler takes a single source file (e.g., `2basic.c`) and translates it into an "object file" (e.g., `2basic.o`). This object file contains machine code, but it's not yet a runnable program.
*   **Role of Header Files (`.h`):** A header file acts as a **contract**. When a source file includes a header (e.g., `#include "1basic.h"`), it's reading the function declarations. This allows the compiler to verify that functions are being called with the correct parameters, but it doesn't provide the actual implementation of those functions.

At the end of this stage, the compiler has created object files that are isolated pieces of the program. For example, `2basic.o` knows it needs to call a function like `createListGraph`, but it has no idea where to find that function's code.

### Stage 2: Linking

*   **What it does:** The linker's job is to take all the compiled object files (`2basic.o`, `1basic.o`, `queue.o`) and "link" them together.
*   **Resolving References:** The linker looks at the "missing" references in each object file. When it sees that `2basic.o` needs `createListGraph`, it searches the other object files until it finds the compiled implementation in `1basic.o`. It then connects, or "links," the call to the implementation.
*   **Final Executable:** Once the linker has resolved all references and connected all the pieces, it bundles them into a single, runnable executable file (e.g., `2basic_run.exe`).

## How to Compile This Project

### Method 1: Simple Compilation (All-in-One)

This method is straightforward and recommended for this project. Provide all the necessary `.c` source files to the compiler at once, and it will handle compilation and linking in a single step.

**To run the algorithm demonstrations in `2basic.c`:**

```bash
# This command compiles and links all required sources into a single executable
gcc 2basic.c 1basic.c queue.c -o 2basic_run
```

**To run the graph example in `1example.c`:**

```bash
gcc 1example.c 1basic.c -o 1example_run
```

### Method 2: Separate Compilation

For larger projects, it's more efficient to compile files separately. This way, if you only change one file, you only need to re-compile that single file before linking.

1.  **Compile each `.c` file into a `.o` object file:** The `-c` flag tells the compiler to "compile only, do not link."

    ```bash
    gcc -c 2basic.c -o 2basic.o
    gcc -c 1basic.c -o 1basic.o
    gcc -c queue.c -o queue.o
    ```

2.  **Link all the `.o` files together to create the executable:**

    ```bash
    gcc 2basic.o 1basic.o queue.o -o 2basic_run
    ```

This two-step process is what build systems like `Make` are designed to automate.