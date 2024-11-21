# Minishell

A simple Unix shell implementation developed as part of the 42 curriculum. This project aims to replicate the basic functionality of a shell while introducing key features such as job control and command parsing.

---

## Features

- Command execution (e.g., `ls`, `echo`, etc.)
- Built-in commands: `cd`, `export`, `unset`, `env`, `exit`, etc.
- Environment variable management
- Pipes (`|`) and redirections (`>`, `<`, `>>`)
- Signal handling (e.g., `Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Error handling with custom messages
- Input parsing, quoting (`'`, `"`), and escaping (`\`)

---

## Getting Started

### Prerequisites

- A Unix-based operating system (Linux or macOS)
- GCC compiler
- GNU Make

### Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:otboumeh/Minishell.git
   cd minishell
Compile the project:

  ```bash
make
```
Run the shell:

```bash
./minishell
```
Usage
Execute standard Unix commands:

```bash
ls -la
```
Use built-in commands:

bash
Copiar código
minishell$ export VAR=value
minishell$ echo $VAR
Chain commands with pipes:

bash
Copiar código
minishell$ ls | grep txt
Redirect input/output:

bash
Copiar código
minishell$ echo "Hello, world!" > file.txt
minishell$ cat < file.txt
File Structure
src/: Source files
main.c: Entry point for the shell
parser.c: Handles input parsing and tokenization
executor.c: Executes commands
include/: Header files
Makefile: Build instructions
Known Limitations
Limited support for some advanced shell features
Background jobs (&) not yet implemented
Future Improvements
Add support for background processes
Enhance error reporting
Improve input parsing for edge cases
