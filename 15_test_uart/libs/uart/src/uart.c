#include <stdio.h>
#include "uart.h"

int uart_api()
{
  #if PRINT_DEBUG_ENABLE
    printf("--------------------------------------------------\n");
    printf("Running the %s() in %s\n" ,__func__ ,__FILE__);
    printf("--------------------------------------------------\n");
  #endif

  printf("hi, test_uart \n");
  printf("--------------------------------------------------\n");
  return 0;
}

int uart_init()
{
  #if PRINT_DEBUG_ENABLE
    printf("--------------------------------------------------\n");
    printf("Running the %s() in %s\n" ,__func__ ,__FILE__);
    printf("--------------------------------------------------\n");
  #endif
  return 0;
}

  int _fd = -1;
  char *_cl_port = NULL;

int setup_serial_port(char port_name[], int serial_speed)
{
  #if 1 //PRINT_DEBUG_ENABLE
    printf("\n-----Run in %s------------------------------\n" ,__func__);
    //printf("#####Get args port_name:speed \"%s\":%d in %s\n" ,port_name ,serial_speed ,__func__);
    printf("#####Get args port_name:speed \"%s\":%d in %s\n"
        ,port_name ,serial_speed ,__func__);
  #endif

  #if PRINT_DEBUG_ENABLE
    printf("-----start setup_serial_port\n");
  #endif
  /*
    //strdup is in string.h
    The strdup() function shall return a pointer to a new string on success. Otherwise, it shall return a null pointer and set errno to indicate the error.
    char *strdup(const char *s);
  */
  _cl_port = strdup(port_name);
  //_cl_port = port_name;
  //_cl_port = strdup("/dev/ttyUSB1");
  //_cl_port="/dev/ttyUSB1";

/* #define  B4800	0000014 */
/* #define  B9600	0000015 */
/* #define  B19200	0000016 */
/* #define  B38400	0000017 */
/* #define  B57600   0010001 */
/* #define  B115200  0010002 */
/* #define  B230400  0010003 */
/* #define  B460800  0010004 */
/* #define  B500000  0010005 */
/* #define  B576000  0010006 */
/* #define  B921600  0010007 */
/* #define  B1000000 0010010 */
/* #define  B1152000 0010011 */
/* #define  B1500000 0010012 */
/* #define  B2000000 0010013 */
/* #define  B2500000 0010014 */
/* #define  B3000000 0010015 */
/* #define  B3500000 0010016 */
/* #define  B4000000 0010017 */
/* #define __MAX_BAUD B4000000 */

  //int baud = serial_speed;
  //int baud = B115200;
  int baud =
             (serial_speed == 115200 )?B115200
            :(serial_speed == 921600 )?B921600
            :(serial_speed == 576000 )?B576000
            :(serial_speed == 500000 )?B500000
            :(serial_speed == 460800 )?B460800
            :(serial_speed == 230400 )?B230400
            :(serial_speed == 57600  )?B57600
            :(serial_speed == 38400  )?B38400
            :(serial_speed == 19200  )?B19200
            :(serial_speed == 9600   )?B9600
            :(serial_speed == 4800   )?B4800
            :B115200; //default config

  struct termios newtio;
  int ret;

  #if PRINT_DEBUG_ENABLE
    printf("run in \"%s\"\n" ,__func__);
  #endif

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
  //newtio.c_cflag = baud | CS8 | CLOCAL | CREAD;
  newtio.c_cflag = baud | CS8 | CLOCAL | CREAD | PARENB;
  //newtio.c_cflag = baud | CS8 | CLOCAL | CREAD | PARENB | PARODD;

#if 0
  newtio.c_cflag &= ~CRTSCTS;
  newtio.c_cflag &= ~CSTOPB;
#endif

  newtio.c_cflag &= ~CRTSCTS;
  newtio.c_cflag &= ~CSTOPB;
  //newtio.c_cflag |= CSTOPB;

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
    printf("-----turn on the serial\n");
  #endif

  return 0;
}

int setup_serial_port_01(char port_name[], int serial_speed)
{
  #if 1 //PRINT_DEBUG_ENABLE
    printf("\n-----Run in %s------------------------------\n" ,__func__);
    printf("#####Get args port_name:speed \"%s\":%d in %s\n"
        ,port_name ,serial_speed ,__func__);
  #endif

  #if PRINT_DEBUG_ENABLE
    printf("-----start setup_serial_port\n");
  #endif
  _cl_port = strdup(port_name);

  int baud =
             (serial_speed == 115200 )?B115200
            :(serial_speed == 921600 )?B921600
            :(serial_speed == 576000 )?B576000
            :(serial_speed == 500000 )?B500000
            :(serial_speed == 460800 )?B460800
            :(serial_speed == 230400 )?B230400
            :(serial_speed == 57600  )?B57600
            :(serial_speed == 38400  )?B38400
            :(serial_speed == 19200  )?B19200
            :(serial_speed == 9600   )?B9600
            :(serial_speed == 4800   )?B4800
            :B115200; //default config

  struct termios newtio;
  int ret;

  #if PRINT_DEBUG_ENABLE
    printf("run in \"%s\"\n" ,__func__);
  #endif

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
  //newtio.c_cflag = baud | CS8 | CLOCAL | CREAD;
  newtio.c_cflag = baud | CS8 | CLOCAL | CREAD | PARENB;
  //newtio.c_cflag = baud | CS8 | CLOCAL | CREAD | PARENB | PARODD;

#if 0
  newtio.c_cflag &= ~CRTSCTS;
  newtio.c_cflag &= ~CSTOPB;
#endif

  newtio.c_cflag &= ~CRTSCTS;
  newtio.c_cflag &= ~CSTOPB;
  //newtio.c_cflag |= CSTOPB;

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
    printf("-----turn on the serial\n");
  #endif

  return 0;
}


void clear_custom_speed_flag()
{
  struct serial_struct ss;
  int ret;

  //ToCheck
  if (ioctl(_fd, TIOCGSERIAL, &ss) < 0) {
    // return silently as some devices do not support TIOCGSERIAL
    return;
  }

  if ((ss.flags & ASYNC_SPD_MASK) != ASYNC_SPD_CUST)
    return;

  ss.flags &= ~ASYNC_SPD_MASK;

  if (ioctl(_fd, TIOCSSERIAL, &ss) < 0) {
    ret = -errno;
    perror("TIOCSSERIAL failed");
    exit(ret);
  }
}

int write_hello_string()
{
  #if PRINT_DEBUG_ENABLE
    printf("-----start try to send one string\n");
  #endif

  int written;
  unsigned char hello_string[]="hello from uart_test!\n";
  int string_number = sizeof(hello_string);
  written = write(_fd, &hello_string ,string_number);

  #if PRINT_DEBUG_ENABLE
    printf("-----send %d byte out\n" ,written);
  #endif
  #if PRINT_DEBUG_ENABLE
    printf("-----send \"%s\"\n" ,hello_string);
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

  return 0;
}

unsigned int write_order_hex()
{
  #if PRINT_DEBUG_ENABLE
    printf("-----start try to send one string\n");
  #endif

  int written;
  //unsigned char hello_string[]="01FEDCBA9876543210";
  //unsigned char hello_string[]="010123456789abcdef";
  //unsigned char hello_hex[]={0x30 ,0x31 ,0x32 ,0x33 ,0x34 ,0x35 ,0x36 ,0x37 ,0x38 ,0x39 ,0x3a ,0x3b ,0x3c ,0x3d ,0x3e ,0x3f};
  unsigned char hello_hex[]={0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  //int hello_hex[]={0x01 ,0x76543210 ,0xfedcba98};
  int hello_hex_number = sizeof(hello_hex);
  //written = write(_fd, &hello_string ,string_number);
  written = write(_fd, hello_hex, hello_hex_number);


  #if PRINT_DEBUG_ENABLE
    printf("-----send %d byte out\n" ,written);
  #endif
  #if PRINT_DEBUG_ENABLE
    int k;
    printf("Send data: hex format is in %s\n" ,__func__);
    for (k=0; k < written; k++)
    {
      printf("%02x ", hello_hex[k]);
    }
    printf("\n");
    //printf("-----send \"%s\"\n" ,hello_hex);
  #endif

  if (written < 0)
  {
    int ret = errno;
    perror("write()");
    exit(ret);
  }
  else if (written != hello_hex_number)
  {
    fprintf(stderr, "ERROR: write() returned %d, not %d\n", written, hello_hex_number);
    exit(-EIO);
  }

  return 0;
}

//write the contents into register with uart
unsigned int write_out_hex_with_reorder(int addr ,int data)
{
  unsigned int data_returned;
  #if PRINT_DEBUG_ENABLE
    printf("\n-----Run in %s\n" ,__func__);
    printf("-----start try to send 0x%x 0x%x\n" ,addr ,data);
  #endif


  int written;
  //unsigned char hello_string[]="01FEDCBA9876543210";
  //unsigned char hello_string[]="010123456789abcdef";
  //unsigned char hello_hex[]={0x30 ,0x31 ,0x32 ,0x33 ,0x34 ,0x35 ,0x36 ,0x37 ,0x38 ,0x39 ,0x3a ,0x3b ,0x3c ,0x3d ,0x3e ,0x3f};
  //unsigned int hello_hex[9]={0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  //unsigned char hello_hex[9]={0x01 ,0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  unsigned char hello_hex[CMD_WRITE_PACKAGE_LEN]={CMD_CODE_WRITE ,0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  hello_hex[0]    = CMD_CODE_WRITE;
  hello_hex[1]    = ((addr >>  0) & 0xff);
  hello_hex[2]    = ((addr >>  8) & 0xff);
  hello_hex[3]    = ((addr >> 16) & 0xff);
  hello_hex[4]    = ((addr >> 24) & 0xff);
  hello_hex[5]    = ((data >>  0) & 0xff);
  hello_hex[6]    = ((data >>  8) & 0xff);
  hello_hex[7]    = ((data >> 16) & 0xff);
  hello_hex[8]    = ((data >> 24) & 0xff);

  #if 0
    int i;
    for (i=0;i<CMD_WRITE_PACKAGE_LEN;i++)
    {
      hello_hex[i] = ((hello_hex[i] >> 4) & 0xf) | ((hello_hex[i] << 4) & 0xf0);
    }
  #endif

  //int hello_hex[]={0x01 ,0x76543210 ,0xfedcba98};
  int hello_hex_number = sizeof(hello_hex);
  //written = write(_fd, &hello_string ,string_number);
  written = write(_fd, hello_hex, hello_hex_number);


  #if PRINT_DEBUG_ENABLE
    printf("-----send %d byte out\n" ,written);
  #endif

  #if PRINT_DEBUG_ENABLE
    int k;
    printf("Send data: hex format is in %s\n" ,__func__);
    for (k=0; k < written; k++)
    {
      printf("%02x ", hello_hex[k]);
    }
    printf("\n");
    //printf("-----send \"%s\"\n" ,hello_hex);
  #endif

  #if PRINT_DEBUG_ENABLE
    if (written < 0)
    {
      int ret = errno;
      perror("write()");
      exit(ret);
    }
    else if (written != hello_hex_number)
    {
      fprintf(stderr, "ERROR: write() returned %d, not %d\n", written, hello_hex_number);
      exit(-EIO);
    }
  #endif

  #if PRINT_DEBUG_ENABLE
    printf("Try to delay 100ms delay\n");
  #endif
  usleep(100000); //int usleep(useconds_t usec);
  //int usleep(useconds_t usec); //<unistd.h>

  #if 1
    //read ack info
    //poll_data_one_time_without_while();
    data_returned = poll_data_one_time_without_while();
  #endif

  return data_returned;
  //return 0;
}

//write the contents into register with uart
unsigned int write_out_hex_with_reorder_01(int addr ,int data)
{
  unsigned int data_returned;
  #if PRINT_DEBUG_ENABLE
    printf("\n-----Run in %s\n" ,__func__);
    printf("-----start try to send 0x%x 0x%x\n" ,addr ,data);
  #endif

  int written;
  unsigned char hello_hex[CMD_WRITE_PACKAGE_LEN]={CMD_CODE_WRITE ,0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  hello_hex[0]    = CMD_CODE_WRITE;
  hello_hex[1]    = ((addr >>  0) & 0xff);
  hello_hex[2]    = ((addr >>  8) & 0xff);
  hello_hex[3]    = ((addr >> 16) & 0xff);
  hello_hex[4]    = ((addr >> 24) & 0xff);
  hello_hex[5]    = ((data >>  0) & 0xff);
  hello_hex[6]    = ((data >>  8) & 0xff);
  hello_hex[7]    = ((data >> 16) & 0xff);
  hello_hex[8]    = ((data >> 24) & 0xff);

  int hello_hex_number = sizeof(hello_hex);
  written = write(_fd, hello_hex, hello_hex_number);

  #if PRINT_DEBUG_ENABLE
    printf("-----send %d byte out\n" ,written);
  #endif

  #if PRINT_DEBUG_ENABLE
    int k;
    printf("Send data: hex format is in %s\n" ,__func__);
    for (k=0; k < written; k++)
    {
      printf("%02x ", hello_hex[k]);
    }
    printf("\n");
  #endif

  #if PRINT_DEBUG_ENABLE
    if (written < 0)
    {
      int ret = errno;
      perror("write()");
      exit(ret);
    }
    else if (written != hello_hex_number)
    {
      fprintf(stderr, "ERROR: write() returned %d, not %d\n", written, hello_hex_number);
      exit(-EIO);
    }
  #endif

  #if PRINT_DEBUG_ENABLE
    printf("Try to delay 100ms delay\n");
  #endif
  usleep(100000); //int usleep(useconds_t usec);//<unistd.h>

  #if 1
    //read ack info
    data_returned = poll_data_one_time_without_while_01();
  #endif

  return data_returned;
}

unsigned int read_one_time_string()
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
  //TODO//
  while(1)
  {
    int serial_port_timeout_number = 1000; //unit is milliseconds
    //extern int poll (struct pollfd *__fds, nfds_t __nfds, int __timeout);
    //int retval = poll(&serial_poll, 1, 1000);
    //int retval = poll(&serial_poll, 1, serial_port_timeout_number);
    #if PRINT_DEBUG_ENABLE
      int retval =
    #endif
    poll(&serial_poll, 1, serial_port_timeout_number);

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
        unsigned char rb[BUFFER_RECEIVED_SIZE];
        //ToCheck
        #if PRINT_DEBUG_ENABLE
        int c =
        #endif
        read(_fd, &rb, sizeof(rb));

        #if PRINT_DEBUG_ENABLE
          printf("Get data, number is 0x%x, rb is \"%s\"\n" ,c ,rb);
          int j;
          printf("get data: hex format is\n");
          for (j=0; j < c; j++)
          {
            printf("%02x ", rb[j]);
          }
          printf("\n");
        #endif

      }
      break;
    }
    //Debug//break;
  }

  return 0;
}

//read the contents from register with uart
unsigned int read_in_hex_with_reorder(int addr)
{
  #if PRINT_DEBUG_ENABLE
    printf("\n-----Run in %s\n" ,__func__);
    //printf("-----start try to send 0x%x 0x%x\n" ,addr ,data);
    printf("-----start try to read 0x%x\n" ,addr);
  #endif


  //int data ,read_count;
  int written;
  //unsigned char hello_string[]="01FEDCBA9876543210";
  //unsigned char hello_string[]="010123456789abcdef";
  //unsigned char hello_hex[]={0x30 ,0x31 ,0x32 ,0x33 ,0x34 ,0x35 ,0x36 ,0x37 ,0x38 ,0x39 ,0x3a ,0x3b ,0x3c ,0x3d ,0x3e ,0x3f};
  //unsigned int hello_hex[9]={0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  //unsigned char hello_hex[9]={0x01 ,0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  //unsigned char hello_hex[5]={0x11 ,0x01 ,0x23 ,0x45 ,0x67};
  //unsigned char hello_hex[5]={0x11 ,0x01 ,0x23 ,0x45 ,0x67};
  unsigned char hello_hex[CMD_READ_PACKAGE_LEN]={CMD_CODE_READ ,0x01 ,0x23 ,0x45 ,0x67};
  hello_hex[0]    = CMD_CODE_READ;
  hello_hex[1]    = ((addr >>  0) & 0xff);
  hello_hex[2]    = ((addr >>  8) & 0xff);
  hello_hex[3]    = ((addr >> 16) & 0xff);
  hello_hex[4]    = ((addr >> 24) & 0xff);
  //hello_hex[5]    = ((data >>  0) & 0xff);
  //hello_hex[6]    = ((data >>  8) & 0xff);
  //hello_hex[7]    = ((data >> 16) & 0xff);
  //hello_hex[8]    = ((data >> 24) & 0xff);

  #if 0
    int i;
    for (i=0;i<CMD_READ_PACKAGE_LEN;i++)
    {
      hello_hex[i] = ((hello_hex[i] >> 4) & 0xf) | ((hello_hex[i] << 4) & 0xf0);
    }
  #endif

  //int hello_hex[]={0x01 ,0x76543210 ,0xfedcba98};
  int hello_hex_number = sizeof(hello_hex);
  //written = write(_fd, &hello_string ,string_number);
  written = write(_fd, hello_hex, hello_hex_number);


  #if PRINT_DEBUG_ENABLE
    printf("-----send %d byte out\n" ,written);
  #endif

  #if PRINT_DEBUG_ENABLE
    int k;
    printf("Send data: hex format is\n");
    for (k=0; k < written; k++)
    {
      printf("%02x ", hello_hex[k]);
    }
    printf("\n");
    //printf("-----send \"%s\"\n" ,hello_hex);
  #endif

  #if PRINT_DEBUG_ENABLE
    if (written < 0)
    {
      int ret = errno;
      perror("write()");
      exit(ret);
    }
    else if (written != hello_hex_number)
    {
      fprintf(stderr, "ERROR: write() returned %d, not %d\n", written, hello_hex_number);
      exit(-EIO);
    }
  #endif

  #if PRINT_DEBUG_ENABLE
    printf("Try to delay 100ms delay\n");
  #endif
  usleep(100000); //int usleep(useconds_t usec);

  return poll_data_one_time_without_while();

  //return 0;
}

//read the contents from register with uart
unsigned int read_in_hex_with_reorder_01(int addr)
{
  #if PRINT_DEBUG_ENABLE
    printf("\n-----Run in %s\n" ,__func__);
    printf("-----start try to read 0x%x\n" ,addr);
  #endif

  int written;
  unsigned char hello_hex[CMD_READ_PACKAGE_LEN]={CMD_CODE_READ ,0x01 ,0x23 ,0x45 ,0x67};
  hello_hex[0]    = CMD_CODE_READ;
  hello_hex[1]    = ((addr >>  0) & 0xff);
  hello_hex[2]    = ((addr >>  8) & 0xff);
  hello_hex[3]    = ((addr >> 16) & 0xff);
  hello_hex[4]    = ((addr >> 24) & 0xff);

  #if 0
    int i;
    for (i=0;i<CMD_READ_PACKAGE_LEN;i++)
    {
      hello_hex[i] = ((hello_hex[i] >> 4) & 0xf) | ((hello_hex[i] << 4) & 0xf0);
    }
  #endif

  int hello_hex_number = sizeof(hello_hex);
  written = write(_fd, hello_hex, hello_hex_number);

  #if PRINT_DEBUG_ENABLE
    printf("-----send %d byte out\n" ,written);
  #endif

  #if PRINT_DEBUG_ENABLE
    int k;
    printf("Send data: hex format is\n");
    for (k=0; k < written; k++)
    {
      printf("%02x ", hello_hex[k]);
    }
    printf("\n");
  #endif

  #if PRINT_DEBUG_ENABLE
    if (written < 0)
    {
      int ret = errno;
      perror("write()");
      exit(ret);
    }
    else if (written != hello_hex_number)
    {
      fprintf(stderr, "ERROR: write() returned %d, not %d\n", written, hello_hex_number);
      exit(-EIO);
    }
  #endif

  #if PRINT_DEBUG_ENABLE
    printf("Try to delay 100ms delay\n");
  #endif
  usleep(100000); //int usleep(useconds_t usec);

  return poll_data_one_time_without_while_01();
}

unsigned int poll_data_one_time_without_while()
{

  struct pollfd serial_poll;
  serial_poll.fd = _fd;
  serial_poll.events |= POLLIN;
  serial_poll.events &= ~POLLOUT;
  //int retval = poll(&serial_poll, 1, 1000);
  //int retval = poll(&serial_poll, 1, 100);
  poll(&serial_poll, 1, 100);

  #if PRINT_DEBUG_ENABLE
    printf("current is serial_poll.events 0x%x\n" ,serial_poll.events);
    printf("current is serial_poll.revents 0x%x\n" ,serial_poll.revents);
  #endif

  //TODO//size need update according the realy application
  //unsigned char data_get_hex[4]={0x01 ,0x23 ,0x45 ,0x67};
  //unsigned char data_get_hex[1024]={0x01 ,0x23 ,0x45 ,0x67};
  unsigned int data_get_hex=0x1234567;

  if (serial_poll.revents & POLLIN)
  {
    unsigned char rb[BUFFER_RECEIVED_SIZE];
    int c = read(_fd, &rb, sizeof(rb));
    #if PRINT_DEBUG_ENABLE
      int j;
      printf("get data: hex format is\n");
      for (j=0; j < c; j++)
      {
        printf("%02x ", rb[j]);
      }
      printf("\n");
    #endif


    switch (c)
    {
      case 1 :
        //get the ack for write
        //data_get_hex[0] = rb[0];
        data_get_hex = (unsigned int) rb[0];
        //return (unsigned int) rb[0];
        break;

      case 5 :
        //unsigned char data_get_hex[5]={0x11 ,0x01 ,0x23 ,0x45 ,0x67};
        /* unsigned char data_get_hex[4]={0x01 ,0x23 ,0x45 ,0x67}; */
        /* data_get_hex[0] = rb[c-1]; */
        /* data_get_hex[1] = rb[c-2]; */
        /* data_get_hex[2] = rb[c-3]; */
        /* data_get_hex[3] = rb[c-4]; */
        data_get_hex  =
                  (0
                  | ( (rb[c-4] << 0 ) & 0xff        )
                  | ( (rb[c-3] << 8 ) & 0xff00      )
                  | ( (rb[c-2] << 16) & 0xff0000    )
                  | ( (rb[c-1] << 24) & 0xff000000  )
                  /* | rb[c-4] << 0 */
                  /* | rb[c-3] << 8 */
                  /* | rb[c-2] << 16 */
                  /* | rb[c-1] << 24 */
                  );

        #if PRINT_DEBUG_ENABLE
          printf("get the ack 0x%x in %s\n" ,(unsigned int) rb[0] ,__func__);
        #endif
        #if PRINT_DEBUG_ENABLE
          printf("get the data 0x%08x in %s\n" ,data_get_hex ,__func__);
        #endif
        //return (unsigned int) data_get_hex;
        break;

      default :
        #if 1
          printf("received data ###error### %d\n" ,c);
        #endif

        #if PRINT_DEBUG_ENABLE
          int j;
          printf("get data: hex format is\n");
          for (j=0; j < c; j++)
          {
            printf("%02x ", rb[j]);
          }
          printf("\n");
        #endif

        data_get_hex  =
                  (0
                  | ( (rb[c-4] << 0 ) & 0xff        )
                  | ( (rb[c-3] << 8 ) & 0xff00      )
                  | ( (rb[c-2] << 16) & 0xff0000    )
                  | ( (rb[c-1] << 24) & 0xff000000  )
                  );

    }

  }

  #if PRINT_DEBUG_ENABLE
    printf("#####Return data_get_hex: 0x%08x in %s\n" ,data_get_hex ,__func__);
  #endif

  return data_get_hex;
  //return (unsigned int) data_get_hex;
  //return 0;
}

unsigned int poll_data_one_time_without_while_01()
{

  struct pollfd serial_poll;
  serial_poll.fd = _fd;
  serial_poll.events |= POLLIN;
  serial_poll.events &= ~POLLOUT;
  poll(&serial_poll, 1, 100);

  #if PRINT_DEBUG_ENABLE
    printf("current is serial_poll.events 0x%x\n" ,serial_poll.events);
    printf("current is serial_poll.revents 0x%x\n" ,serial_poll.revents);
  #endif

  unsigned int data_get_hex=0x1234567;

  if (serial_poll.revents & POLLIN)
  {
    unsigned char rb[BUFFER_RECEIVED_SIZE];
    int c = read(_fd, &rb, sizeof(rb));
    #if PRINT_DEBUG_ENABLE
      int j;
      printf("get data: hex format is\n");
      for (j=0; j < c; j++)
      {
        printf("%02x ", rb[j]);
      }
      printf("\n");
    #endif

    switch (c)
    {
      case 1 :
        //get the ack for write
        data_get_hex = (unsigned int) rb[0];
        break;

      case 5 :
        data_get_hex  =
                  (0
                  | ( (rb[c-4] << 0 ) & 0xff        )
                  | ( (rb[c-3] << 8 ) & 0xff00      )
                  | ( (rb[c-2] << 16) & 0xff0000    )
                  | ( (rb[c-1] << 24) & 0xff000000  )
                  );

        #if PRINT_DEBUG_ENABLE
          printf("get the ack 0x%x in %s\n" ,(unsigned int) rb[0] ,__func__);
        #endif
        #if PRINT_DEBUG_ENABLE
          printf("get the data 0x%08x in %s\n" ,data_get_hex ,__func__);
        #endif
        break;

      default :
        #if 1
          printf("received data ###error### %d\n" ,c);
        #endif

        #if PRINT_DEBUG_ENABLE
          int j;
          printf("get data: hex format is\n");
          for (j=0; j < c; j++)
          {
            printf("%02x ", rb[j]);
          }
          printf("\n");
        #endif

        data_get_hex  =
                  (0
                  | ( (rb[c-4] << 0 ) & 0xff        )
                  | ( (rb[c-3] << 8 ) & 0xff00      )
                  | ( (rb[c-2] << 16) & 0xff0000    )
                  | ( (rb[c-1] << 24) & 0xff000000  )
                  );

    }

  }

  #if PRINT_DEBUG_ENABLE
    printf("#####Return data_get_hex: 0x%08x in %s\n" ,data_get_hex ,__func__);
  #endif

  return data_get_hex;
}

unsigned int read_in_hex_with_reorder_send_comand_only(int addr)
{
  #if PRINT_DEBUG_ENABLE
    printf("\n-----Run in %s\n" ,__func__);
    //printf("-----start try to send 0x%x 0x%x\n" ,addr ,data);
    printf("-----start try to read 0x%x\n" ,addr);
  #endif


  //int data ,read_count;
  int written;
  //unsigned char hello_string[]="01FEDCBA9876543210";
  //unsigned char hello_string[]="010123456789abcdef";
  //unsigned char hello_hex[]={0x30 ,0x31 ,0x32 ,0x33 ,0x34 ,0x35 ,0x36 ,0x37 ,0x38 ,0x39 ,0x3a ,0x3b ,0x3c ,0x3d ,0x3e ,0x3f};
  //unsigned int hello_hex[9]={0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  //unsigned char hello_hex[9]={0x01 ,0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xab ,0xcd ,0xef};
  //unsigned char hello_hex[5]={0x11 ,0x01 ,0x23 ,0x45 ,0x67};
  unsigned char hello_hex[CMD_READ_PACKAGE_LEN]={CMD_CODE_READ ,0x01 ,0x23 ,0x45 ,0x67};
  hello_hex[0]    = CMD_CODE_READ;
  hello_hex[1]    = ((addr >>  0) & 0xff);
  hello_hex[2]    = ((addr >>  8) & 0xff);
  hello_hex[3]    = ((addr >> 16) & 0xff);
  hello_hex[4]    = ((addr >> 24) & 0xff);
  //hello_hex[5]    = ((data >>  0) & 0xff);
  //hello_hex[6]    = ((data >>  8) & 0xff);
  //hello_hex[7]    = ((data >> 16) & 0xff);
  //hello_hex[8]    = ((data >> 24) & 0xff);

  #if 0
    int i;
    for (i=0;i<CMD_READ_PACKAGE_LEN;i++)
    {
      hello_hex[i] = ((hello_hex[i] >> 4) & 0xf) | ((hello_hex[i] << 4) & 0xf0);
    }
  #endif

  //int hello_hex[]={0x01 ,0x76543210 ,0xfedcba98};
  int hello_hex_number = sizeof(hello_hex);
  //written = write(_fd, &hello_string ,string_number);
  written = write(_fd, hello_hex, hello_hex_number);


  #if PRINT_DEBUG_ENABLE
    printf("-----send %d byte out\n" ,written);
  #endif

  #if PRINT_DEBUG_ENABLE
    int k;
    printf("Send data: hex format is\n");
    for (k=0; k < written; k++)
    {
      printf("%02x ", hello_hex[k]);
    }
    printf("\n");
    //printf("-----send \"%s\"\n" ,hello_hex);
  #endif

  #if PRINT_DEBUG_ENABLE
    if (written < 0)
    {
      int ret = errno;
      perror("write()");
      exit(ret);
    }
    else if (written != hello_hex_number)
    {
      fprintf(stderr, "ERROR: write() returned %d, not %d\n", written, hello_hex_number);
      exit(-EIO);
    }
  #endif
  return 0;
}

unsigned int or_write_register(int addr ,int data)
{
  unsigned int temp_data;

  #if PRINT_DEBUG_ENABLE
    printf("\n-----Run in [%s]------------------------------\n" ,__func__);
    printf("#####Get args addr:data 0x%08x:0x%08x in %s\n" ,addr ,data ,__func__);
  #endif

  //temp_data = write_out_hex_with_reorder(addr ,data);
  temp_data = write_out_hex_with_reorder_01(addr ,data);

  #if 1 //PRINT_DEBUG_ENABLE
    printf("#####Write addr:data [0x%08x:0x%08x], Get _ack:[0x%08x]\n" ,addr ,data ,temp_data);
  #endif

  return temp_data;
}

unsigned int ir_read_register(int addr)
{
  unsigned int temp_data;
  #if PRINT_DEBUG_ENABLE
    printf("\n-----Run in [%s]------------------------------\n" ,__func__);
    printf("#####Get args addr 0x%08x in %s\n" ,addr ,__func__);
  #endif

  //temp_data = read_in_hex_with_reorder(addr);
  temp_data = read_in_hex_with_reorder_01(addr);

  #if 1 //PRINT_DEBUG_ENABLE
    printf("#####Read addr:[0x%08x], Get data:[0x%08x]\n" ,addr ,temp_data);
  #endif

  return temp_data;
}

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
