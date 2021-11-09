#ifndef __ARG_READ_H__
#define __ARG_READ_H__

  #ifndef PRINT_DEBUG_ENABLE
    #define PRINT_DEBUG_ENABLE 1
  #endif

  //macro and data type here
  #define MAX_STRING_LENGTH 100


  //function list
  //int arg_read(char *argv[], char *input_arg_list[][3][MAX_STRING_LENGTH]);
  int arg_read(int argc ,char *argv[], char input_arg_list[][3][MAX_STRING_LENGTH]);
  int print_arg_list(char input_arg_list[][3][MAX_STRING_LENGTH]);

#endif
