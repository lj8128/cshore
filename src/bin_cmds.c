#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#include "../include/bin_cmds.h"
#include "../include/pid_print_cmds.h"
#include "../include/errors.h"
#include "../include/ansi.h"

void bin(const char* cmd) {
  errno = 0;
  pid_t fork_return_val;
  fork_return_val = fork();
  if (fork_return_val == -1) {
    print_errno_errs();
  } else if (fork_return_val == 0) {
    int exec_return_val;
    if(strcmp(cmd, "w") == 0) {
      exec_return_val = execl("/usr/bin/w", "", NULL);
    } else if(strcmp(cmd, "ps") == 0) {
      exec_return_val = execl("/bin/ps", "", NULL);
    } else if(strcmp(cmd, "less") == 0) {
      exec_return_val = execl("/usr/bin/less", "", NULL);
    } else if(strcmp(cmd, "head") == 0) {
      exec_return_val = execl("/usr/bin/head", "", NULL);
    } else if(strcmp(cmd, "tail") == 0) {
      exec_return_val = execl("/usr/bin/tail", "", NULL);
    } else {
      char* full_bin_cmd = malloc(4 + strlen(cmd));
      strcat(full_bin_cmd, "bin_");
      strcat(full_bin_cmd, cmd);
      no_cmd_err(full_bin_cmd);
      free((void *) full_bin_cmd);
    }
    if(exec_return_val == -1) {
      print_errno_errs();
      exit(EXIT_FAILURE);
    }
  } else {
    int child_exit_status;
    if(waitpid(fork_return_val, &child_exit_status, 0) == -1) {
      print_errno_errs();
    } else if(WEXITSTATUS(child_exit_status) == 1){
      const char* red_bars = color_red("==");
      printf("%sA C-Shore child with pid \033[1m%i\033[22m exited with status \033[1m%s\033[22m%s\n", red_bars, fork_return_val, strsignal(WEXITSTATUS(child_exit_status)), red_bars);
      free((void *) red_bars);
    }
  }
}

void fork_test()
{
  errno = 0;
  pid_t fork_return_val;
  fork_return_val = fork();
  if (fork_return_val == 0)
  {
    printf("I am the **child** process. My PID is: ");
    print_my_pid();
    printf("\nMy parent's pid is: ");
    print_parent_pid();
    printf("\n");
    printf("I am now going to run the OS's ps program.\nIt will show some of the processes running on this computer.\n");
    char divider[] = "==================================\n";
    printf("%s", divider);
    if(execl("/bin/ps", "", NULL) == -1) {
      print_errno_errs();
      exit(EXIT_FAILURE);
    }
  }
  else if (fork_return_val == -1)
  {
    print_errno_errs();
  }
  else
  {
    int child_exit_status;
    if(waitpid(fork_return_val, &child_exit_status, 0) == -1) {
      print_errno_errs();
    }
    char divider[] = "==================================\n";
    printf("%s", divider);
    printf("I am the **parent** process, the C-Shore program. My PID is: ");
    print_my_pid();
    printf("\nMy child with PID %i exited with status %i", fork_return_val, WEXITSTATUS(child_exit_status));
    printf("\n");
  }
}