#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/repl.h"
#include "../include/errors.h"
#include "../include/file_print_cmds.h"
#include "../include/file_nav_cmds.h"
#include "../include/file_create_cmds.h"

int run_REPL()
{
  bool exit = false;
  char prompt[] = ">> ";
  char input[1024];

  while (!exit)
  {
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    // Replace trailing \n with null char
    input[strlen(input) - 1] = '\0';

    if (strcmp(input, "exit") == 0)
    {
      exit = true;
    }
    else if (strcmp(input, "pwd") == 0)
    {
      pwd();
    }
    else if (strcmp(input, "ls") == 0)
    {
      ls();
    }
    else if (strstr(input, "cd ") == input) {
      char* path = malloc(strlen(input) - 3);
      memmove(path, &input[3], strlen(input)-3);
      cd(path);
      free((void *) path);
    }
    else
    {
      no_cmd_err(input);
    }
  }

  
  return 0;
}
