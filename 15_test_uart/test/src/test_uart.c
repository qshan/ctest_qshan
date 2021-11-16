#include <stdio.h>
#include "test_uart.h"
//#include "say_hello_uart.h"
//#include "test_uart_shared.h"

#include <stdlib.h>     /*  */
#include <unistd.h>     /* UNIX Standard Definitions         */
#include <termios.h>    /* POSIX Terminal Control Definitions */
#include <sys/file.h>   /*  */
#include <fcntl.h>      /* File Control Definitions           */
#include <sys/ioctl.h>  /* ioctl - control device */
#include <linux/serial.h> /*  */
#include <errno.h>      /* ERROR Number Definitions           */
#include <sys/types.h>  /*  */
#include <sys/stat.h>   /* stat - display file or file system status */
#include <strings.h>    /* strings - print the strings of printable characters in files */
#include <string.h>     /* string operations */

int _fd = -1;
char *_cl_port = NULL;
unsigned char * _write_data;

static void exit_handler(void)
{
  if (_fd >= 0) {
    flock(_fd, LOCK_UN);
    close(_fd);
  }

  if (_cl_port) {
    free(_cl_port);
    _cl_port = NULL;
  }

//  if (_write_data) {
//    free(_write_data);
//    _write_data = NULL;
//  }
}

int main()
{
  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("===================================================\n");
    printf("hello test_uart \n");
    printf("\n");
  #endif

  #if 1
    say_hello_uart();
    printf("Try to call function_shared_test_uart(1), get: 0x%x \n"
        , function_shared_test_uart(1)
        );
  #endif

  int uart_api();

  #if 1
    //uart operation here start
    atexit(&exit_handler);

    //setup_serial_port()
    {
      #if PRINT_DEBUG_EN
        printf("#####start setup_serial_port\n");
      #endif
      _cl_port = strdup("/dev/ttyUSB1");
      //_cl_port="/dev/ttyUSB1";
      int baud = B115200;

      struct termios newtio;
      int ret;

      #if PRINT_DEBUG_ENABLE
        printf("_cl_port is \"%s\"\n" ,_cl_port);
      #endif
      _fd = open(_cl_port, O_RDWR | O_NONBLOCK);
      #if PRINT_DEBUG_ENABLE
        printf("open %s, get _fd is %d\n" ,_cl_port ,_fd);
      #endif

      if (_fd < 0) {
        ret = -errno;
        perror("Error opening serial port");
        exit(ret);
      }

      /* Lock device file */
      //ToCheck
      if (flock(_fd, LOCK_EX | LOCK_NB) < 0) {
        ret = -errno;
        perror("Error failed to lock device file");
        exit(ret);
      }
      //ToCheck
      bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */

      /* man termios get more info on below settings */
      newtio.c_cflag = baud | CS8 | CLOCAL | CREAD;

#if 0
      newtio.c_cflag &= ~CRTSCTS;
      newtio.c_cflag &= ~CSTOPB;
#endif

      newtio.c_iflag = 0;
      newtio.c_oflag = 0;
      newtio.c_lflag = 0;
      // block for up till 128 characters
      newtio.c_cc[VMIN] = 128;
      // 0.5 seconds read timeout
      newtio.c_cc[VTIME] = 5;

      /* now clean the modem line and activate the settings for the port */
      //ToCheck
      tcflush(_fd, TCIOFLUSH);
      //ToCheck
      tcsetattr(_fd,TCSANOW,&newtio);
      #if PRINT_DEBUG_ENABLE
        printf("#####turn on the serial\n");
      #endif

    }

#if 0
    //clear_custom_speed_flag()
    {
      #if PRINT_DEBUG_ENABLE
        printf("#####start clear_custom_speed_flag\n");
      #endif
      struct serial_struct ss;
      int ret;

      //ToCheck
      if (ioctl(_fd, TIOCGSERIAL, &ss) < 0)
      {
        // return silently as some devices do not support TIOCGSERIAL
        return 1;
      }

      if ((ss.flags & ASYNC_SPD_MASK) != ASYNC_SPD_CUST)
      {
        return 1;
      }

      ss.flags &= ~ASYNC_SPD_MASK;

      if (ioctl(_fd, TIOCSSERIAL, &ss) < 0)
      {
        ret = -errno;
        perror("TIOCSSERIAL failed");
        exit(ret);
      }
      //TODO//return 0;
    }
#endif

    {
      #if PRINT_DEBUG_ENABLE
        printf("#####start try to send one string\n");
      #endif

      int written;
      unsigned char hello_string[]="hello uart test!\n";
      int string_number = sizeof(hello_string);
      written = write(_fd, &hello_string ,string_number);

      #if PRINT_DEBUG_ENABLE
        printf("#####send %d byte out\n" ,written);
      #endif

      if (written < 0)
      {
        int ret = errno;
        perror("write()");
        exit(ret);
      }
      else if (written != string_number)
      {
        fprintf(stderr, "ERROR: write() returned %d, not %d\n", written, string_number);
        exit(-EIO);
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
