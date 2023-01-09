#include <stddef.h>
#include <string.h>

#include "../include/ansi.h"

const char* color_red(const char *text)
{
  char set_red[] = "\033[31m";
  char reset_col[] = "\033[0m";
  size_t result_length = strlen(set_red) + strlen(text) + strlen(reset_col);
  char result[result_length];
  strcpy(result, set_red);
  strcat(result, text);
  strcat(result, reset_col);
  return result;
}