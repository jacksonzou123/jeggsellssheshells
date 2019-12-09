#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include "get.h"

int main(int argc, char *argv[]) {
  while (1) {
    // printf("GIMME THAT COMMAND: ");
    // char *input[] = getArgs();
    // int i = 0;
    // while (*(input+i)) {
    //   printf("i: %d, str: [%s]\n", i, *(input+i));
    //   i++;
    // }
    // *(input+i) = NULL;
    // //printf("size of array: %ld\n", sizeof(input));
    // int status = execvp("ls", input);
    // printf("status: %d , error: %s\n", status, strerror(errno));
    char cwd[100];
    getcwd(cwd, sizeof(cwd));
    printf("%s ", cwd);
    char input[100];
    fgets(input, 100, stdin);
    if (input[strlen(input) - 1] == '\n') {
      input[strlen(input) - 1] = '\0';
    }
    char *p = input;
    char *list[100];
    int i = 0;
    while (p) {
      char * hold = strsep(&p, " ");
      *(list+i) = hold;
      i++;
    }
    *(list+i) = NULL;
    if (!strcmp(*(list), "cd")) {
      int status = chdir(*(list+1));
      if (status == -1) {
        printf("Error: %s\n", strerror(errno));
      }
    }
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
        //i = 0;
        // while (*(input+i)) {
        //   printf("[%s]\n", *(input+i));
        //   i++;
        // }
        if (status == -1) {
          printf("Error: %s\n", strerror(errno));
        }
        return 0;
      }
    }
    //printf("%s", input);
  }
  return 0;
}
