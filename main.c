#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "get.h"

int main(int argc, char *argv[]) {
  while (1) {
    printf("GIMME THAT COMMAND: ");
    char ** input = getArgs();
    int i = 0;
    while (*(input+i)) {
      printf("i: %c, str: [%s]\n", i, *(input+i));
      i++;
    }
    *(input+i+1) = NULL;
    int status = execvp(input[0], input);
    printf("status: %d , error: %s\n", status, strerror(errno));
    // int f = fork();
    // printf("f: %d\n", f);
    // if (f) {
    //   //parent
    //   int * status;
    //   wait(status);
    //   printf("parent finished\n");
    // }
    // else {
    //   //kid
    //   int status = execvp(input[0], input);
    //   i = 0;
    //   while (*(input+i)) {
    //     printf("[%s]\n", *(input+i));
    //     i++;
    //   }
    //   printf("status: %s\n", strerror(errno));
    //   return 0;
    // }
    //printf("%s", input);
  }
  return 0;
}
