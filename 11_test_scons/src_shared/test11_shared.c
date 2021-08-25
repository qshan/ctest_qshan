#include <stdio.h>

int function_shared_test11(int arg0)
{
  printf("-------------------------------------------------- \n");
  printf("hi, test11 \n");
  printf("Here is the funciton %s \n", __func__);
  printf("the argo is 0x%x\n",arg0);
  printf("-------------------------------------------------- \n");
  return (arg0 + 1);
}
