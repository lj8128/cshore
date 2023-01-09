#include <string.h>
#include "../include/startup.h"

void print_welcome(char version[])
{
  char divider[] = "==================================\n";
  char welcomeMessage[] = "Welcome to the C-Shore, a C-Shell!";
  printf("%s", divider);
  printf("%s\n%s%s\n", welcomeMessage, "CurrentVersion: ", version);
  printf("%s", divider);
}