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
#include "parse.h"

/*========
Inputs: char *input, char *array[]
Outputs: None

Parses through the contents of input and splits the string up into smaller strings and puts it
into array
========*/
void parseSpace(char *input, char *array[]) {
  int i = 0;
  while (input) {
    char * hold = strsep(&input, " ");
    if (*hold != '\0'){
      *(array+i) = hold;
      i++;
    }
  }
  *(array+i) = NULL;
}

/*========
Inputs: char *list[]
Outputs: returns an integer used as a true/false

Looks for whether a '>' character exists in the command.
If it does, it will redirect and run the command
=========*/
int checkout(char *list[]) {
  int i = 0;
  int out = 0;
  while (*(list+i)) {
    if (!strcmp(*(list+i), ">")) {
      out = i;
    }
    i++;
  }
  if (out) {
    int newfile = open(*(list+out+1), O_CREAT|O_TRUNC|O_WRONLY);
    if (newfile == -1) {
      printf("Error: %s\n", strerror(errno));
    }
    else {
      int f = fork();
      if (f) {
        int * status;
        wait(status);
        return out;
      }
      else {
        //int stdout = dup(1);
        dup2(newfile, 1);
        *(list+out) = NULL;
        int status = execvp(list[0], list);
        if (status == -1) {
          printf("Error: %s\n", strerror(errno));
        }
        return out;
      }
    }
  }
  return 0;
}

/*========
Inputs: char *list[]
Outputs: returns an integer used as a true/false

Looks for whether a '<' character exists in the command.
If it does, it will redirect and run the command
=========*/
int checkin(char *list[]) {
  int i = 0;
  int in = 0;
  while (*(list+i)) {
    if (!strcmp(*(list+i), "<")) {
      in = i;
    }
    i++;
  }
  if (in) {
    int newfile = open(*(list+in+1), O_RDONLY);
    if (newfile == -1) {
      printf("Error: %s\n", strerror(errno));
    }
    else {
      int f = fork();
      if (f) {
        int * status;
        wait(status);
        return in;
      }
      else {
        //int stdout = dup(1);
        dup2(newfile, 0);
        *(list+in) = NULL;
        int status = execvp(list[0], list);
        if (status == -1) {
          printf("Error: %s\n", strerror(errno));
        }
        return in;
      }
    }
  }
  return 0;
}

// int checkpipe(char *list[]) {
//   int i = 0;
//   int check = 0;
//   while (*(list+i)) {
//     if (!strcmp(*(list+i), "|")) {
//       check = i;
//     }
//     i++;
//   }
//   if (check) {
//     int pp[2];
//     int e = pipe(pp);
//     if (e == -1) {
//       printf("Error: %s", strerror(errno));
//     }
//     int f = fork();
//     *(list+check) = NULL;
//     if (!f) {
//       dup2(pp[1], 1);
//       execvp(list[0], list);
//       return check;
//     }
//     else {
//       int * status;
//       wait(status);
//       dup2(pp[0], 0);
//       int i = 0;
//       char *newarray[100];
//       while ((*list+check+i+1)) {
//         *(newarray+i) = *(list+check+i+1);
//         i++;
//       }
//       *(newarray+i) = NULL;
//       execvp(newarray[0], newarray);
//       return check;
//     }
//   }
//   return 0;
// }
