#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "get.h"

char ** getArgs() {
  char input[100];
  fgets(input, 100, stdin);
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }
  char * p = input;
  char **list = calloc(100, sizeof(char*));
  int i = 0;
  while (p) {
    char * hold = strsep(&p, " ");
    //list = realloc(list, (i+1) * sizeof(char*));
    //printf("size of array: %d\n", i+1);
    *(list+i) = hold;
    i++;
  }
  *(list+i) = NULL;
  // printf("%d\n",i);
  //i = 0;
  // while (*(list + i)) {
  //   printf("[%s]\n", *(list + i));
  //   i++;
  // }
  return list;
}
