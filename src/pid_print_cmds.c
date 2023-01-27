#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "../include/pid_print_cmds.h"

void print_my_pid() {
  printf("%i", getpid());
};

void print_parent_pid() {
  printf("%i", getppid());
};