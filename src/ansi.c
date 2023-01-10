#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "../include/ansi.h"

const char* color_red(const char *text)
{
  char set_red[] = "\033[31m";
  char reset_color[] = "\033[0m";
  size_t result_length = strlen(set_red) + strlen(text) + strlen(reset_color);
  char* result = malloc(result_length);
  strcpy(result, set_red);
  strcat(result, text);
  strcat(result, reset_color);
  return result;
}