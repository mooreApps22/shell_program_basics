# __SHELL PROGRAM BASICS__

[GGR](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

## **A shell program is a app that allows interacting with the Operating System**
### **Parts of a Shell Program**

Note: All syntax is in bash!

1. The Parser
* Interprets the command line and puts it into ```typedef struct s_cmd_tab```
* ```t_cmd_tab``` stores the commands that will be executed
2. The Executor
* Takes ```t_cmd_tab``` generated by the parser and creates a process for each command
  * if necessary it creates pipes ```|``` to read/write between each process
* If there is any **redirection** it will need to redirect stdin (0), stdout(1), or stderr(2)
  * standard input  (the keyboard)
  * standard output (the terminal)
  * standard output (the terminal, but with system error messages)
* Basic systax of a full command line
  * Command A | Command B | Command C > outfile < infile 2> errfile
    * **Important Notes!!**
      * Command A creates an output to B, and B to C ...
      * ```>``` will output the outfile
      * ```<``` will output from the infile into Command A
      * ```2>``` will output any standard error message to the errfile
        * The normal output for an stderr is stdout
        * stderr will only output to errfile in two cases that I know of:
          * The final pipeline command has and error
          * The entire pipeline inside is self contained
          * ```>&``` will output a simple command error to errfile
```
ls | grep "all" | non-command > output < infile 2> errfile
```
```
{ ls --invalid-option | grep "all" | wc -c; } > output < infile 2> errfile
```
3. Shell Subsystems
* Environment Variables
  * ```$VAR``` is mostly the same as ```${VAR}```
    * ```${VAR}``` will keep variable from getting combined
    * EX: ```echo -n ${PATH}$'\n'```
  * A shell should be able to set, expand, and print environment variables
    * set:  ```export MY_VAR="Hello World"```
    * expand: ```echo $MY_VAR``` (notice there is no quotes)
    * print: ```echo "Hello, $MY_VAR"``` or ```echo '$MY_VAR'``` (notice there is quotes)
* Wildcards
  * arguments contain a sequence of characters and a ```*``` and are expanded to all files that match inside the directory
  * ```echo *.txt``` would output the text of all file in the directory that end in '.txt'
* Subshells
  * Arguments between ``` `` ``` are exectued and output to the shell
4. ddd
