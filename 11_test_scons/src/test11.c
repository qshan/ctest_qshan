#include <stdio.h>
#include "say_hello_11.h"
#include "test11_shared.h"
int main()
{
  printf("\n");
  printf("===================================================\n");
  printf("hello test11 \n");
  printf("\n");

  say_hello11();
  printf("Try to call function_shared_test11(1), get: 0x%x \n"
      , function_shared_test11(1)
      );

  printf("\n");
  printf("Bye test11 \n");
  printf("===================================================\n");
  printf("\n");
  return 0;

}
