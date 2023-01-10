#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "../include/file_print_cmds.h"
#include "../include/errors.h"

void pwd()
{
  // To see why second arg. of getcwd is 0, see man page of getcwd.
  const char *cur_dir = getcwd(NULL, 0);
  printf("%s\n", cur_dir);
}

void ls() {
  const char* cur_dir = getcwd(NULL,0);
  ls_with_arg(cur_dir);
  free((void *) cur_dir);
}

void ls_with_arg(const char* path)
{
  errno = 0;
  DIR* dir_stream = opendir(path);
  if(dir_stream==NULL) {
    if(errno != 0) {
      print_errno_errs();
    } else {
      return;
    }
  }

  errno = 0;
  struct dirent* file = readdir(dir_stream);
  while(file != NULL) {
    const char* cur_file_name = file->d_name;
    if(cur_file_name[0] != '.') {
      printf("%s  ", cur_file_name); 
    }
    file = readdir(dir_stream);
  } 
  if(errno != 0) {
    print_errno_errs();
  } 
  printf("\n");
  closedir(dir_stream); 
}