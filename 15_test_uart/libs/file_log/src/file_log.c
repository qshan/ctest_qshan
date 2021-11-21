#include "file_log.h"

  FILE *p_fp_global;
  char *p_file_name[200];

  #if 1
  //file operation files
  #include <stdio.h>
  int file_init_func(char *p_file_name[200])
  //int file_init_func(char *p_file_name[1024])
  //FILE file_init_func(char *p_file_name[])
  //FILE file_init_func()
  {

    #if PRINT_DEBUG_ENABLE
      printf("Run in %s\n" ,__func__);
    #endif

    //return the file handler
    //FILE *p_fp;
    //char *p_file_name[] = "test_uart_file_test.txt";
    //p_file_name = "test_uart_file_test.txt";
    //FILE *fopen(char *filename, char *mode);
    //p_fp = fopen("test_uart_file_test.txt", "a+");
    //p_fp = fopen(p_file_name, "a+");
    //p_fp = fopen("test_uart_file_test.txt", "a+");
    p_fp_global = fopen(*p_file_name, "a+");
    //fclose(p_fp);
    fclose(p_fp_global);

    //return *p_fp;
    return 0;
  }

    //int file_write_func(FILE *p_fp ,char argv[])
    int file_write_func(char argv[MAX_NUMBER_PER_LINE])
    {

    #if PRINT_DEBUG_ENABLE
      printf("Run in %s\n" ,__func__);
    #endif

    //file write case
    //open, write and close
    //p_fp = fopen("test_uart_file_test.txt", "a+");
    int wr_ret  = 0;
    //char argv[] = "Try to write file test from test_uart.c file!\n";
    //char argv[] = "Try to write file test from test_uart.c file!";
    //argv = "Try to write file test from test_uart.c file!";

    #if PRINT_DEBUG_ENABLE
      printf("the write contents is %s\n" ,argv);
    #endif
    //write(int p_fd, const void *buf, size_t count);

    //p_fp = fopen(p_file_name, "a+");
    //p_fp = fopen(p_file_name, "w+");

    #if PRINT_DEBUG_ENABLE
      printf("Try #####fwrite() function in %s\n" ,__func__);
    #endif

 //   //p_fp = fopen(p_file_name, "a+");
    //size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    //fread, fwrite - binary stream input/output

    //wr_ret = fwrite(argv ,sizeof(argv) ,1 ,p_fp);
    #if PRINT_DEBUG_ENABLE
      printf("wr_ret is 0x%x\n" ,wr_ret);
    #endif

    #if PRINT_DEBUG_ENABLE
      printf("Try #####fwrite() function in %s\n" ,__func__);
    #endif
    //wr_ret = fwrite(argv ,1 ,sizeof(argv) ,p_fp);
    ////int fprintf(FILE *fp, char *format, e1,e2,......en);
    //#if PRINT_DEBUG_ENABLE
    //  printf("wr_ret is 0x%x\n" ,wr_ret);
    //#endif

    p_fp_global = fopen(*p_file_name, "a+");

    #if PRINT_DEBUG_ENABLE
      printf("Try #####fprintf() function in %s\n" ,__func__);
    #endif
    //fprintf(p_fp ,"fprintf %s\n" ,argv);
    fprintf(p_fp_global ,"fprintf %s\n" ,argv);

    //fclose(p_fp);
    fclose(p_fp_global);

      return 0;
    }

    int file_read_by_line_func(FILE *p_fp )
    {
    //file read and write case
    //open, write and close

    char      *line_buf = NULL;
    int       line_count = 0;

    //char *p_file_name = "test_uart_file_test.txt";
    //p_fp = fopen(p_file_name, "a+");

    #if PRINT_DEBUG_ENABLE
      printf("Run in %s\n" ,__func__);
    #endif


    p_fp = p_fp_global;

    #if PRINT_DEBUG_ENABLE
      //printf("Try to open file %s\n\r" ,p_file_name);
      printf("Try to open file %s\n" ,*p_file_name);
    #endif

    #if 1
      p_fp = fopen(*p_file_name, "r+");

      #if PRINT_DEBUG_ENABLE
        printf("Try #####getline() function in %s\n" ,__func__);
      #endif

      size_t    line_buf_size = 0;
      ssize_t   line_size;

      /* Get the first line of the file. */
      line_size = getline(&line_buf, &line_buf_size, p_fp);

      line_count  = 0;
      /* Loop through until we are done with the file. */
      while (line_size >= 0)
      {

        /* Increment our line count */
        line_count++;

        #if PRINT_DEBUG_ENABLE
          /* Show the line details */
          printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s\n"
              ,line_count ,line_size ,line_buf_size ,line_buf);
        #endif

        /* Get the next line */
        line_size = getline(&line_buf ,&line_buf_size ,p_fp);
      }

      #if PRINT_DEBUG_ENABLE
        /* Show the line details */
        printf("The total lines is %d\n" ,line_count);
      #endif

      fclose(p_fp);
    #endif

    //not worked
    #if 0
      p_fp = fopen(*p_file_name, "r+");
      #if PRINT_DEBUG_ENABLE
        printf("Try #####fscanf() function in %s\n" ,__func__);
      #endif
      char line_data[128] = {0};
      //while (fscanf(p_fp, "%[^\n]", line_data) != EOF)
      while (fscanf(p_fp, "%[\n]" ,line_data) != EOF)
      {
        printf("> %s\n", line_data);
      }
      fclose(p_fp);
    #endif

    //worked for txt format with end of line char
    #if 0
      p_fp = fopen(p_file_name, "r+");
      #if PRINT_DEBUG_ENABLE
        printf("Try #####fgets() function in %s\n" ,__func__);
      #endif
      //char *path;
      //char line[MAX_LINE_LENGTH] = {0};
      char line[128] = {0};
      //char line[128];
      //unsigned int line_count = 0;
      line_count = 0;

      /* Get each line until there are none left */
      //while (fgets(line, MAX_LINE_LENGTH, file))
      while (fgets(line, 128, p_fp))
      {
        /* Print each line */
        printf("line[%06d]: %s", ++line_count, line);

        /* Add a trailing newline to lines that don't already have one */
        if (line[strlen(line) - 1] != '\n')
        {
          printf("\n");
        }
      }

      #if PRINT_DEBUG_ENABLE
        /* Show the line details */
        printf("The total lines is %d\n" ,line_count);
      #endif

      fclose(p_fp);
    #endif

    /* Free the allocated line buffer */
    //free(line_buf);
    //line_buf = NULL;

    /* Close the file now that we are done with it */
    //fclose(p_fp);

    //int fscanf(FILE *fp, char *format, e1,e2,......en);
    //int fread(char *buf, unsigned size, unsigned n, FILE *fp);
    //fclose(p_fp);

    return 0;
  }
  #endif