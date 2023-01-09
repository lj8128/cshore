#include <stdio.h>
#include "include/startup.h"
#include "include/repl.h"

int main(int argc, char **argv)
{
  print_welcome("0.1.0");
  int exit_code = run_REPL();
  return exit_code;
}