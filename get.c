#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "get.h"

char * getArgs() {
  char * input = malloc(100 * sizeof(char));
  fgets(input, 100, stdin);
  return input;
}
