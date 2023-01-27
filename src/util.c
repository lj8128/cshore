#include <stdlib.h>
#include <string.h>

#include "../include/util.h"

const char *extract_path(const char *input, int cmd_length)
{
  int cmd_space_length = cmd_length + 1;
  char *path = malloc(strlen(input) - cmd_space_length);
  memmove(path, &input[cmd_space_length], strlen(input) - cmd_space_length);
  return path;
}

const char *extract_bin_cmd(const char *input)
{
  int bin_prefix_length = 4;
  char *cmd = malloc(strlen(input) - bin_prefix_length);
  memmove(cmd, &input[bin_prefix_length], strlen(input) - bin_prefix_length);
  return cmd;
}
