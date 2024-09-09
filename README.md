# __SHELL PROGRAM BASICS__ (GNU/Linux specific)

## Useful Links

[GGR](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

 [flex_wiki](https://en.wikipedia.org/wiki/Flex_(lexical_analyser_generator)) | [flex_docs](https://westes.github.io/flex/manual/) |
[bison_wiki](https://en.wikipedia.org/wiki/GNU_Bison) | [bison_docs](https://www.gnu.org/software/bison/manual/bison.html#FAQ)

[Bash](https://www.gnu.org/software/bash/manual/bash.html#What-is-Bash_003f)|
[C](https://sourceware.org/glibc/manual/latest/html_mono/libc.html#Library-Summary)|
[Make](https://www.gnu.org/software/make/manual/make.html)|
[Autoconf](https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.72/autoconf.html)

# What is a shell

1. A shell is a macro processor that executes commands
   * A **macro processor** means it can expan text and symbols into larger expressions
2. A Unix shell is both a command interpreter and a programming language
   * The terminal is an interface for GNU utilities
   * The programming language features allow these utilities to be combined
   * Files containing one command or more are treated as a command themself
     * Custom command files have the same status as system commands in ```\bin```
     * This also user or groups to make custome environments to automate common tasks
3. A shell can be in interactive mode or non-ineractive mode
   * Interactive mode means you input from the keyboard
   * Non-interactive is when the shell is execuating file commands
4. A shell can execute commands **synchronously** and **asynchronously**
   * Synchronous commands means have to complete execution before accepting more input
   * Asynchronous commands will perform execution while accepting more input for addition execution
   * **Redirection** allows for advance control of the contents of commands' enviroment
5. **Built-in commands** or **builtins**
   * Some builtins cannot be implemented outisde of the shell because it affects the shell
     * ```cd``` ```break``` ```continue``` ```exec```
   * Some builtins can be used in separate utilities, but as easier to use as as builtin commands
     * ```history``` ```getopts``` ```kill``` ```pwd```
6. The embedded programming lanuaguages are what make shells powerful, but executing commands is essential
   * Like most programming languages the shell has:
     * Variables, flow control constructs, quoting, and functions
   * The shells features are geared specifically for interactive use rather than to augment the programming lanuge
   * Interactive features include:
     * Job Control
     * Command line editing
     * Command history
     * Aliases
    
#   Basic Shell Features

1. Bash
   * Bash, the Bourne-Again Shell is an evolution of the Borne Shell
     * Rules for evaluation and quoting are taken from POSIX specs for Unix
2. Building blocks
   * Commands
   * Control structures
   * Shell functions
   * Shell parameters
   * Shell expansions
   * Redirections - direct input/output from and to named files
   * Execution
3. Shell Syntax and Order of Read Operations
  * ```#``` Comments are ignored
  * Shell reads its input and divides it up into **words** and **symbols**
    * The quoting rules are applied specify tokens
  * Tokens are parsed into commands and other constructs
    * Removes the special meaning of certain words or characters
    * Expands others
    * Redirects I/O as needed
    * Executes the specified command
    * Waits for the command's exit status
    * Makes the exit status available for further use
4. Shell Operation
   * 1. Reads input from a file or string argument
     2. Breaks input into words & operators (obeys quoting rules)
     3. Parses tokens into simple commands and compound commands
     4. Performs expansions
     5. Peforms redirections
     6. Executes command
     7. May wait on command to complete and then collect its exit status
5.  Quoting
    * **Metacharacter** are ```|``` ```&``` ```;``` ```(``` ```)``` ```<``` ```>``` also included 'space', 'tab', and 'newline'
      * When unquoted separates words
    * Quoting is used to remove special meaning to metacharacters, making it's just a character
    * Three quoting mechanisms: 
      * Escape charcter ```\```
      * Single quotes - preserves the literal value of each character
      * Double quotes - preserves literal value of all characters, except ```$``` ``` ` ``` ```\```
 6. Shell Commands
    * Simple command example: ```echo "Hello world"```
    * Multiple simple commands can be arranged together in various way to make Compound commands
    * **Reserved words** are keywords that are used to begin and end
    * ```for i in {1..5}; do echo "Num: $i"; done```
      * ```for``` ```in``` ```do``` ```done``` are all reserve words 
