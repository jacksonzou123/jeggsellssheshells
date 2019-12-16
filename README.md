jeggsellssheshells
by Jackson Zou and Jeff Lin PD04

Features:
  Can execute commands (works for all the ones I know exists)
  Can execute more than one command per line (using ;)
  Redirects using < or >

Attempted:
  Pipes do not work

Bugs:
  If you try to redirect with a incorrect command, the program pauses and stops doing anything
  If there are 2 semicolons in a row, it segfaults (with or without a space)
  Trying to use a command with both < and > breaks
  If you try to cd to ~, it says bad address

Files & Function Headers:
  main.c
    main file for controlling everything (the big boss)

  get.c
    /*======== void printcwd() ========
    Inputs: None
    Outputs: None

    Prints the current working direction
    ====================*/

    /*======== char * getInput() ========
    Inputs: char input[]
    Outputs: returns a pointer to the array of characters that was typed into the command line

    Gets the command line input and removes the newline character at the end of the array
    ====================*/

  parse.c
    /*======== void parseSpace() ========
    Inputs: char *input, char *array[]
    Outputs: None

    Parses through the contents of input and splits the string up into smaller strings and puts it
    into array
    ====================*/

    /*======== int checkout() ========
    Inputs: char *list[]
    Outputs: returns an integer used as a true/false

    Looks for whether a '>' character exists in the command.
    If it does, it will redirect and run the command
    ====================*/

    /*======== int checkin() ========
    Inputs: char *list[]
    Outputs: returns an integer used as a true/false

    Looks for whether a '<' character exists in the command.
    If it does, it will redirect and run the command
    ====================*/
