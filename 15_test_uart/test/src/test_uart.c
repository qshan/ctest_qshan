#include <stdio.h>
//#include "say_hello_uart.h"
//#include "test_uart_shared.h"
#include "test_uart.h"

//  extern int _fd;
//  extern char *_cl_port;
//unsigned char * _write_data;

#include <unistd.h> //for usleep(usecond_t usec)

int main()
{
  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("===================================================\n");
    printf("hello test_uart \n");
    printf("\n");
  #endif

  #if 0
    say_hello_uart();
    printf("Try to call function_shared_test_uart(1), get: 0x%x \n"
        , function_shared_test_uart(1)
        );
  #endif

  #if 0
    int uart_api();
  #endif

  //todo
  //uart and timestamp
  #if 1
    //uart operation here start
    char serial_port_name[]="/dev/ttyUSB0";
    int serial_speed = B115200;

    #if PRINT_DEBUG_ENABLE
      printf("check %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif
    //init the port
    setup_serial_port(serial_port_name, serial_speed);
    #if PRINT_DEBUG_ENABLE
      printf("open %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif
    //clear the status of serial
    clear_custom_speed_flag();

    #if 1
    //for time_log check here
    init_time_stamp_log();
    #endif
    //try to write hello string
    //write_hello_string();
    //write_order_hex();
    //write_out_hex_with_reorder(0x7654321 ,0xfedcba98);

    //TODO//worked
    #if 0
    write_out_hex_with_reorder(0x01234567 ,0x89abcdef);
    #endif

    //TODO//worked?????
    #if 0
    read_in_hex_with_reorder(0x01234567);
    #endif

    #if 1
    unsigned int  temp_data;
      temp_data = ir_read_register(0x00801024);
      #if 1 //PRINT_DEBUG_ENABLE
        printf("get temp_data is 0x%08x in %s\n" ,temp_data ,__func__);
      #endif
      or_write_register(0x00801024 ,0x65457c04);

      //ir 00801024     ;# read LDO_CTRL_REG, check default value 65457c04
      //or 00801024 65457c04  ;# 1. LDO enable

      temp_data = ir_read_register(0x00801000);
      #if 1 //PRINT_DEBUG_ENABLE
        printf("get temp_data is 0x%08x in %s\n" ,temp_data ,__func__);
      #endif
      or_write_register(0x00801000 ,0x0c800b10);

      //ir 00801000		;# read PLL_CTRL_REG, check default value 0c800b10
      //or 00801000 0c800b10    ;# 2. set DDRC_PLL_DDR_DIV_SEL 0, set PLL_LOOP_PI_SEL 0

    #endif


    //try to read the data from serial port
    //TODO//read_one_time_string();

    //TODO
    #if 0
    #if PRINT_DEBUG_ENABLE
      printf("Try to delay 1000ms delay\n");
    #endif
    usleep(1000000); //int usleep(useconds_t usec);

    clock_gettime(CLOCK_MONOTONIC, &last_timeout);
    //for time_log check here
    check_time_stamp_log_data();
    #endif

    atexit(&exit_handler);
  #endif

  //TODO
  #if 0
    //function for file operation
    *p_file_name  = "test_uart_file_test_func.txt";
    file_init_func(p_file_name);

    char argv[] = "Try to write file test with func!";
    file_write_func(argv);
    file_read_by_line_func(p_fp_global);
  #endif

  #if 0
{

  //file operation files
  #include <stdio.h>
  //FILE file_init_func(char *p_file_name)
  {
    //return the file handler
    FILE *p_fp;
    char *p_file_name[] = "test_uart_file_test.txt";
    //FILE *fopen(char *filename, char *mode);
    //p_fp = fopen("test_uart_file_test.txt", "a+");
    //p_fp = fopen(p_file_name, "a+");
    //fclose(p_fp);

    //return fp;
//  }
//  //file_write_func(FILE *p_fp ,char argv[])
//  {
    //file write case
    //open, write and close
    //p_fp = fopen("test_uart_file_test.txt", "a+");
    int wr_ret  = 0;
    //char argv[] = "Try to write file test from test_uart.c file!\n";
    char argv[] = "Try to write file test from test_uart.c file!";
    #if PRINT_DEBUG_ENABLE
      printf("the write contents is %s\n" ,argv);
    #endif
    //write(int p_fd, const void *buf, size_t count);

    p_fp = fopen(p_file_name, "a+");
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

    #if PRINT_DEBUG_ENABLE
      printf("Try #####fprintf() function in %s\n" ,__func__);
    #endif
    fprintf(p_fp ,"fprintf %s\n" ,argv);

    fclose(p_fp);

    //return 0;
//  }
//  //file_read_by_line_func(FILE *p_fp )
//  {
    //file read and write case
    //open, write and close

    char      *line_buf = NULL;
    int       line_count = 0;

    //char *p_file_name = "test_uart_file_test.txt";
    //p_fp = fopen(p_file_name, "a+");

    #if PRINT_DEBUG_ENABLE
      //printf("Try to open file %s\n\r" ,p_file_name);
      printf("Try to open file %s\n" ,p_file_name);
    #endif

    #if 1
      p_fp = fopen(p_file_name, "r+");

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
      p_fp = fopen(p_file_name, "r+");
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
    free(line_buf);
    line_buf = NULL;

    /* Close the file now that we are done with it */
    //fclose(p_fp);

    //int fscanf(FILE *fp, char *format, e1,e2,......en);
    //int fread(char *buf, unsigned size, unsigned n, FILE *fp);
    //fclose(p_fp);

    //return 0;
  }

}
  #endif


  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("Bye test_uart \n");
    printf("===================================================\n");
    printf("\n");
  #endif
  return 0;
}
