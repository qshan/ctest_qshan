#include <stdio.h>
#include "test_uart.h"
//#include "say_hello_uart.h"
//#include "test_uart_shared.h"

#include <stdio.h>
#include <stdlib.h>     /*  */
#include "test_uart.h"
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
#include <poll.h>       /* poll, ppoll - wait for some event on a file descriptor */

#if 0
  int _fd = -1;
  char *_cl_port = NULL;
#endif

  extern int _fd;
  extern char *_cl_port;

unsigned char * _write_data;

#if 0
//static void exit_handler(void)
void exit_handler()
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
#endif

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
    char serial_port_name[]="/dev/ttyUSB1";
    int serial_speed = B115200;

    #if PRINT_DEBUG_ENABLE
      printf("check %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif
    setup_serial_port(serial_port_name, serial_speed);
    #if PRINT_DEBUG_ENABLE
      printf("open %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif

    #if 0
    //setup_serial_port(char port_name[], int serial_speed)
    {
      #if PRINT_DEBUG_ENABLE
        printf("#####start setup_serial_port\n");
      #endif
      /*
        //strdup is in string.h
        The strdup() function shall return a pointer to a new string on success. Otherwise, it shall return a null pointer and set errno to indicate the error.
        char *strdup(const char *s);
      */
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

      newtio.c_cflag &= ~CRTSCTS;
      newtio.c_cflag &= ~CSTOPB;
      //two_stop_bit//newtio.c_cflag |= CSTOPB;

      #if PRINT_DEBUG_ENABLE
        printf("current newtio.c_cflag is 0x%x\n" ,newtio.c_cflag);
        printf("current CRTSCTS is 0x%x\n"  ,(newtio.c_cflag&CRTSCTS));
        printf("current CSTOPB is 0x%x\n"   ,(newtio.c_cflag&CSTOPB));
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
    #endif

    clear_custom_speed_flag();
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

    write_hello_string();
    #if 0
    //int write_hello_string()
    {
      #if PRINT_DEBUG_ENABLE
        printf("#####start try to send one string\n");
      #endif

      int written;
      unsigned char hello_string[]="hello from uart_test!\n";
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

    read_one_time_string();
    #if 0
    //try to pull the status
    //int read_one_time_string()
    {
      //ToCheck
      struct pollfd serial_poll;
      serial_poll.fd = _fd;
      serial_poll.events |= POLLIN;
      //serial_poll.events |= POLLOUT;
      serial_poll.events &= ~POLLOUT;
      ///* Event types that can be polled for.  These bits may be set in `events'
         //to indicate the interesting event types; they will appear in `revents'
         //to indicate the status of the file descriptor.  */
      //#define POLLIN    0x001     /* There is data to read.  */
      //#define POLLPRI   0x002     /* There is urgent data to read.  */
      //#define POLLOUT   0x004     /* Writing now will not block.  */

      #if PRINT_DEBUG_ENABLE
        printf("current is serial_poll.events 0x%x\n" ,serial_poll.events);
        printf("current is serial_poll.revents 0x%x\n" ,serial_poll.revents);
      #endif

      //try to poll status
      while(1)
      {
        int serial_port_timeout_number = 1000;
        //extern int poll (struct pollfd *__fds, nfds_t __nfds, int __timeout);
        //int retval = poll(&serial_poll, 1, 1000);
        int retval = poll(&serial_poll, 1, serial_port_timeout_number);
        #if PRINT_DEBUG_ENABLE
          printf("Check retval : serial_poll.revents is %d:0x%x\n" ,retval ,serial_poll.revents);
        #endif

        if (serial_poll.revents & POLLIN)
        {
          #if PRINT_DEBUG_ENABLE
            printf("Read data now\n");
          #endif
          //read operation here
          {
            #define RECEIVED_BUFFER_SIZE   1024
            unsigned char rb[RECEIVED_BUFFER_SIZE];
            //ToCheck
            int c = read(_fd, &rb, sizeof(rb));

            #if PRINT_DEBUG_ENABLE
              printf("Get data, number is 0x%x, rb is \"%s\"\n" ,c ,rb);
            #endif
          }
          break;

        }

        //Debug//break;
      }

    }
    #endif

    atexit(&exit_handler);
  #endif


  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("Bye test_uart \n");
    printf("===================================================\n");
    printf("\n");
  #endif
  return 0;
}
