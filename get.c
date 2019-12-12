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

void printcwd() {
  char cwd[100];
  getcwd(cwd, sizeof(cwd));
  printf("%s ", cwd);
}

char* getInput(char input[]) {
  fgets(input, 100, stdin);
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }
  char *p = input;
  return p;
}
