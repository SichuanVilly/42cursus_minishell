# 42Cursus Minishell

This project is part of the **42cursus** curriculum and consists of creating a simple UNIX shell. The purpose of this project is to understand how shells work, handle system calls, and implement key concepts like process control, file descriptors, and pipes.

## Table of Contents

- [Description](#description)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Built With](#built-with)

## Description

**Minishell** is a basic shell implementation that mimics the functionalities of a standard Unix shell. This project allows you to run commands, handle pipes, and redirect input/output, providing a solid foundation for understanding the inner workings of shell environments.

### Key Features:

- Command parsing and execution
- Input/output redirection (`>`, `<`)
- Piping between commands (`|`)
- Environment variable handling
- Signal handling (e.g., handling `SIGINT`)

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/SichuanVilly/42cursus_minishell.git
    ```

2. Navigate to the project directory:

    ```bash
    cd 42cursus_minishell
    ```

3. Compile the project using `make`:

    ```bash
    make
    ```

    This will create the `minishell` executable.

## Usage

To run the **minishell**, simply execute:

```bash
./minishell
```
## Built With

- **C** – The programming language used to implement the shell.
- **Make** – The build automation tool used to compile the project.
- **System Calls** – Utilized for command execution, file manipulation, and process control.

