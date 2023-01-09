#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../include/repl.h"
#include "../include/ansi.h"

int run_REPL()
{
  bool exit = false;
  char prompt[] = ">> ";
  char input[1024];

  while (!exit)
  {
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    //Replace trailing \n with null char
    input[strlen(input) - 1] = '\0';

    if (strcmp(input, "exit") == 0) {
      exit = true;
    } else if(strcmp(input, "ls") == 0) {
      printf("<A list of the contents of your current directory>\n");
    } else {
      fprintf(stderr, "%s: %s is not a C-shore command\n", color_red("ERR"), input);
    }
  }

  return 0;
}
