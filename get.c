#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "get.h"

char ** getArgs() {
  char input[100];
  fgets(input, 100, stdin);
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }
  char * p = input;
  char ** list = 0;
  int i = 0;
  while (p) {
    char * hold = strsep(&p, " ");
    list = realloc(list, (i+1) * sizeof(char*));
    *(list+i) = hold;
    i++;
  }
  printf("%d\n",i);
  i = 0;
  while (*(list + i)) {
    printf("[%s]\n", *(list + i++));
  }
  return list;
}
