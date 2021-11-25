#include <stdio.h>
#include "test_main.h"
//#include "say_hello_.h"
//#include "test_shared.h"
int main()
{
  printf("\n");
  printf("===================================================\n");
  printf("hello test \n");
  printf("\n");

  say_hello();
  printf("Try to call function_shared_test(1), get: 0x%x \n"
      , function_shared_test(1)
      );

  printf("\n");
  printf("Bye test \n");
  printf("===================================================\n");
  printf("\n");
  return 0;

}
