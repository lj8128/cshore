#include <errno.h>
#include <unistd.h>

#include "../include/file_nav_cmds.h"
#include "../include/errors.h"

void cd(const char* path) {
  errno = 0;
  if(chdir(path) == -1) {
    print_errno_errs();
  }
}