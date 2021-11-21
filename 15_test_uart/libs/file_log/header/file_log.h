#ifndef __FILE_LOG_H__
#define __FILE_LOG_H__
//file_log.h

#include <stdio.h>

#ifndef PRINT_DEBUG_ENABLE
  #define PRINT_DEBUG_ENABLE  1
#endif

#define MAX_NUMBER_PER_LINE   200
  extern FILE *p_fp_global;
  extern char *p_file_name[];

  //FILE file_init_func(char *p_file_name[]);
  //int file_init_func(char *p_file_name[1024]);
  int file_init_func(char *p_file_name[]);
  int file_write_func(char argv[]);
  int file_read_by_line_func(FILE *p_fp );

#endif
