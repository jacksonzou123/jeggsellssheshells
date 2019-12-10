#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include "parse.h"

void parseSpace(char *input, char *array[]) {
  int i = 0;
  while (input) {
    char * hold = strsep(&input, " ");
    *(array+i) = hold;
    i++;
  }
  *(array+i) = NULL;
}

int countCharacter(char *input, char delimiter) {
  int i = 0;
  int final = 0;
  while (*(input + i)) {
    if (*(input+i) == delimiter) {
      final++;
    }
    i++;
  }
  return final;
}
