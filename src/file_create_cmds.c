#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

#include "../include/file_create_cmds.h"
#include "../include/errors.h"

void my_mkdir(const char *path)
{
  errno = 0;
  mode_t default_permissions = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
  if (mkdir(path, default_permissions) == -1)
  {
    print_errno_errs();
  }
}

void touch(const char *path)
{
  errno = 0;
  FILE* new_file = fopen(path, "a+");
  if (new_file == NULL)
  {
    print_errno_errs();
  }
  else
  {
    if (fclose(new_file) == EOF)
    {
      print_errno_errs();
    }
  }
}