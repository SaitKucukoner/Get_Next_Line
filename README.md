# Get Next Line

### Project Overview
---

The Get Next Line project aims to implement a function that allows reading a file line by line from a given file descriptor.
This function is capable of handling newline characters properly and ensures that leftover data is preserved for the next call.

The project provides a solid understanding of:

Buffer management

Static variables

Dynamic memory allocation

---

### How It Works

The file is read in chunks of size BUFFER_SIZE.

If a newline (\n) is encountered, the function stops and returns the line including the newline character.

Any leftover data after the newline is stored in a static variable (buffer) and used in the next call.

Both newline and null terminator cases are properly handled.

---

### Files

get_next_line.c → Core implementation of the function.

get_next_line.h → Header file containing function prototypes and macros.

get_next_line_utils.c → Utility functions (string operations, memory handling, etc.).

---
