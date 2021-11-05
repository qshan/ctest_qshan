#include <stdio.h>
#include "test14.h"
//#include "say_hello_14.h"
//#include "test14_shared.h"
int main(int argc, char *argv[])
{
  int i;//for arg print control
  int value_returned=0;

  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("===================================================\n");
    printf("hello test14 \n");
    printf("\n");
  #endif

  #if 0
    say_hello14();
  #endif

  #if 0
    printf("Try to call function_shared_test14(1), get: 0x%x \n"
        , function_shared_test14(1)
        );
  #endif

  {
    printf("------------------------------\n");
    //printf("#####Get argument is %s\n", *argv);
    printf("#####Get argc is %d\n"    , argc);
    printf("#####Get argv is ");
    for(i=0;i<argc;i++)
    {
      printf(" %s" , argv[i]);
    }
    printf("\n");

    for(i=0;i<argc;i++)
    {
      printf("#####Get argv[%d] is %s\n" ,i ,argv[i]);
    }
    printf("------------------------------\n");
  }

  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("Bye test14 \n");
    printf("===================================================\n");
    printf("\n");
    #endif

  printf("value_returned is %d\n" ,value_returned);
  return value_returned;

}
