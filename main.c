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

    printf("Gimme that command: ");
    char input[100];
    fgets(input, 100, stdin);
    if (input[strlen(input) - 1] == '\n') {
      input[strlen(input) - 1] = '\0';
    }

    char *p = input;
    char **list[10];
    int i = 0, y = 0, x = 0;
    while (p) {
      char * hold = strsep(&p, ";");
      char *list2[100];
      x = 0;
      while (hold) {
        char * hold2 = strsep(&hold, " ");
        if (*hold2 != '\0') {
          *(list2+x) = hold2;
          x++;
        }
      }
      *(list2+x) = NULL;
      // *(list+i) = list2;
      //list = realloc(list, (i+1) * sizeof(char*));
      //printf("size of array: %d\n", i+1);
      // *(list+i) = hold;
      int f = fork();
      // printf("f: %d\n", f);
      if (f) {
        //parent
        int * status;
        wait(status);
        // printf("parent finished\n");
      }
      else {
        //kid
        int status = execvp(list2[0], list2);
        //i = 0;
        // while (*(input+i)) {
        //   printf("[%s]\n", *(input+i));
        //   i++;
        // }
        //printf("status: %s\n", strerror(errno));
        return 0;
      }
      i++;
    }
    *(list+i) = NULL;
    // for (x = 0; list[x]; x++) {
    //   printf("Section\n");
    //   for (y = 0; list[x][y]; y++) {
    //     printf("[%s]\n",list[x][y]);
    //   }
    // }

    // *(list+i) = NULL;
    // for (i = 0; *(list + i); i++){
    //   printf("[%s]\n",*(list+i));
    // }

    // int f = fork();
    // // printf("f: %d\n", f);
    // if (f) {
    //   //parent
    //   int * status;
    //   wait(status);
    //   // printf("parent finished\n");
    // }
    // else {
    //   //kid
    //   int status = execvp(list[0], list);
    //   //i = 0;
    //   // while (*(input+i)) {
    //   //   printf("[%s]\n", *(input+i));
    //   //   i++;
    //   // }
    //   //printf("status: %s\n", strerror(errno));
    //   return 0;
    // }
    // //printf("%s", input);
  }
  return 0;
}
