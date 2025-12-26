*This project has been created as part of the 42 curriculum by <heychong>.*

## Description

'get_next_line' is a C function that reads a file descriptor line by line and returns each line on succesive calls.
The returned line includes the terminating newline character ('\n'), except when the end of file is reached and the file does not end with a newline.

The goal of this project is to understand and correctly manage:
- Buffered input using 'read()'
- Dynamic memory allocation
- Static variables
- Edge cases related to EOF, buffer size, and memory safety

This function is designed to wordk with any valid file descriptor, including files and standard input.

---

## Instructions

### complication

The project must be compiled with a configurable buffer size using the 'BUFFER_SIZE' macro.

Example:

'''zsh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c

## Resources

None
