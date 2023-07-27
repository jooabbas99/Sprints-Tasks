# `Makefile` task

## Task Description

You are required to create a `Makefile` for the "Led Sequence v.1" project. The
`Makefile` should handle the compilation and linking process.

## Requirements

1. Create a `Makefile` named "Makefile" in the root directory of the project.
2. The `Makefile` should have at least two targets: "all", "flash", and "clean".
3. The "all" target should be the default target that compiles the source code
   and generates the binary executable.
4. The `Makefile` should handle dependencies and recompile only the necessary
   files when changes occur.
5. The `Makefile` should use appropriate compiler flags and options for
    compilation, such as enabling warnings and specifying the output
    directories, e.g., `-Wall` and `-Werror`.
6. The "clean" target should remove all generated object files and the binary
    executable from the "build" and "bin" directories, respectively.
7. The `Makefile` should provide a way to clean the project by invoking the
    "clean" target.
8. The `Makefile` must make use of make automatic variables, pattern rules
    (explicit and implicit), and built-in functions.
9. The flash rule must program the `MCU` using `avrdude`.

## Submission

You should submit the `Makefile` you created along with your led sequence
project. Ensure that the `Makefile` is named `Makefile` and is placed in the
root directory of the project.

**Note 1**: `Makefile`s are typically used in Unix-like environments, such as
Linux or macOS, but you can also use tools like GNU Make on Windows. Make sure
to install `WSL` properly.

**Note 2**: Don't submit any object or executable file

**Note 3**: Don't submit any editor files like the ones located in `.vscode`
