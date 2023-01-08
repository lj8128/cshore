#include <string.h>
#include "../include/startup.h"

void print_welcome(char version[])
{
  printf("==================================\n%s\n%s%s\n==================================\n", "Welcome to the C-Shore, a C-Shell!", "CurrentVersion: ", version);
}