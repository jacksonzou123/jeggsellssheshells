#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "get.h"
#include "parse.h"

int main(int argc, char *argv[]) {
  while (1) {
    printcwd();
    //print current directory

    char input[100];
    char *p = getInput(input);
    //get user input

    while (p) {
      char * hold = strsep(&p, ";");
      //printf("%s\n", hold);

      char *list[100];
      parseSpace(hold, list);
      //put input string into array

      //int pipes = checkpipe(list);
      int out = checkout(list);
      int in = checkin(list);
      //if (pipes) {}
      if (out) {}
      else if (in) {}
      else if (!strcmp(*(list), "cd")) {
        int status = chdir(*(list+1));
        if (status == -1) {
          printf("Error: %s\n", strerror(errno));
        }
      }
      //runs if user is trying to change directory
      else if (!strcmp(*(list), "exit")) {
        return 0;
      }
      //runs if user is trying to exit the program

      else {

        int f = fork();
        //printf("f: %d\n", f);
        if (f) {
          //parent
          int * status;
          wait(status);
          //printf("parent finished\n");
        }
        else {
          //kid
          int status = execvp(list[0], list);
          if (status == -1) {
            printf("Error: %s\n", strerror(errno));
          }
          return 0;
        }
      }
    }
    //any other command
  }
  return 0;
}
