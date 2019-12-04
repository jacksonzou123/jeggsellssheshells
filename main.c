#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "get.h"

int main(int argc, char *argv[]) {
  while (1) {
    printf("GIMME THAT COMMAND: ");
    char * input = getArgs();
    printf("%s", input);
  }
  return 0;
}
