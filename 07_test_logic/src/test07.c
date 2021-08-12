#include <stdio.h>
#include "say_hello_07.h"
int main()
{
  printf("hello test07 \n");
  say_hello07();

  unsigned int udata1, udata2, udata3;
  unsigned int uresult1, uresult2, uresult3;

  udata1 = 0x0;
  udata2 = 0x11;
  udata3 = 0x11;

  uresult1 = udata1 ^ udata2;
  printf("hi, udata1 ^ udata2 = 0x%x \n", uresult1);

  uresult2 = udata2 ^ udata3;
  printf("hi, udata2 ^ (udata3) = 0x%x \n", uresult2);

  uresult3 = udata2 ^ udata1;
  printf("hi, udata3 ^ udata1 = 0x%x \n", uresult3);




  return 0;
}
