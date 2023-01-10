#include <stdio.h>
#include <stdlib.h>

#include "../include/errors.h"
#include "../include/ansi.h"

void no_cmd_err(const char *input)
{
  const char *red_err = color_red("ERR");
  fprintf(stderr, "%s: %s is not a C-shore command\n", red_err, input);
  free((void *)red_err);
}

void print_errno_errs()
{
  const char *red_err = color_red("ERR");
  perror(red_err);
  free((void *)red_err);
}