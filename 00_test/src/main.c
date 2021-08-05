/*
 * main.c
 *
 *  Created on: Oct 26, 2016
 *    Author: qshan
 */
#include <stdio.h>
#include <stdlib.h>
#include <practice.h>

int main()

{
  printf("\n##this is start of %s in %s##\n", __func__, __FILE__);
  int i=0;


#if 0
//test for behavior of sizeof for pointer
  unsigned int array[3][2] = {{1,2},{3,4},(5,6)};
  unsigned int *ptr1;
  unsigned int *ptr2;
  unsigned int *ptr3;

  ptr1 = array;
  ptr2 = array[0];
  ptr3 = &array[0][1];
  //printf("array is %x\n", array);
  printf("sizeof(array) is %d \n", (sizeof(array)));
  printf("sizeof(typeof(array)) is %d \n", (sizeof(typeof(array))));
  printf("sizeof(array[0]) is %d \n", (sizeof(array[0])));
  printf("sizeof(typeof(array[0])) is %d \n", (sizeof(typeof(array[0]))));
  printf("sizeof(array[0][0]) is %d \n", (sizeof(array[0][0])));
  printf("sizeof(ptr1) is %d \n", (sizeof(ptr1)));
  printf("sizeof(typeof(ptr1)) is %d \n", (sizeof(typeof(ptr1))));
  printf("sizeof(ptr2) is %d \n", (sizeof(ptr2)));
  printf("sizeof(ptr3) is %d \n", (sizeof(ptr3)));
  printf("sizeof(*ptr1) is %d \n", (sizeof(*ptr1)));
  printf("sizeof(*ptr2) is %d \n", (sizeof(*ptr2)));
  printf("sizeof(*ptr3) is %d \n", (sizeof(*ptr3)));
#endif
#if 0
  for (i=0;i<10;i++)
  printf("Hell C %d time \n", (i+1));
#endif


#if 0
//just example for my son
/**/
//
  i=0;
  if(i==0)
  {
    //code block
    printf("i=0 is right\n");
  }else
  {
    //code block
    printf("i != 0\n");
    printf("i is really not equal 0\n");
  }

//add in qcavi pc

  printf("the code is end here\n");

#endif


#if 0
//for the enmu test
enum TRAFFIC_TYPE {type_one, type_two, type_three, type_four};

enum TRAFFIC_TYPE sellection;
  sellection = type_three;

switch (sellection)
{
case type_one :
  printf("current is type_one \n");
  break;
case type_two :
  printf("current is type_two \n");
  break;
case type_three :
  printf("current is type_three \n");
  break;
case type_four :
  printf("current is type_four \n");
  break;
default :
  //code here;
  printf("current is default branch \n");
  break;
}

#endif

#if 0
//test for behavior of sizeof for array
  int Array[]={10,9,8,2,6,5,4,3,7,1};
  //printf("sizeof(Array) = %d\n", (sizeof(Array)));
  //printf("sizeof(Array[0]) = %d\n", (sizeof(Array[0])));
  //printf("sizeof(Array)/sizeof(Array[0]) = %d\n", (sizeof(Array)/sizeof(Array[0])));
  printf("sizeof(Array)/sizeof(Array[0]) = %d\n", (NUMBEROFARRAYD1(Array)));
  print_int_array(Array, (sizeof(Array)/sizeof(Array[0])));
  sort_int(Array, sizeof(Array)/sizeof(Array[0]));
  print_int_array(Array, (sizeof(Array)/sizeof(Array[0])));
#endif



#if 0
//dlist
  //declare a struct
  qs_DLIST_NODE qs_dlist;
  //declare a pointer of struct
  qs_DLIST_PTR qs_dlistptr;
  //qs_DLIST_NODE *qs_dlistptr;

#if 0
  printf("\n [integer]: sizeof(int) is %d", sizeof(int));
  printf("\n [struct]: sizeof(qs_dlist) is %d", sizeof(qs_dlist));
  printf("\n [pointer of struct]: sizeof(qs_dlistptr) is %d", sizeof(qs_dlistptr));
  //printf("\n Here is code line number %d in %s \n", __LINE__, __FILE__);
#endif

  qs_dlistptr = qs_dlist_create();
  qs_dlist_insert_R(qs_dlistptr, 1, 2);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_insert_R(qs_dlistptr, 2, 3);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_insert_R(qs_dlistptr, 7, 4);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_insert_R(qs_dlistptr, 2, 5);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_insert_R(qs_dlistptr, 2, 6);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_insert_R(qs_dlistptr, 5, 9);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_insert_R(qs_dlistptr, 4, 7);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_delete(qs_dlistptr, 5);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_delete(qs_dlistptr, 7);
  qs_dlist_print(qs_dlistptr);
  qs_dlist_delete(qs_dlistptr, 2);
  qs_dlist_print(qs_dlistptr);

#endif

#if 0
//queue##### FIFO
  qs_QUEUE Q;
  qs_InitQueue(&Q, 5);
  qs_PrintQueue(&Q);
  qs_EnQueue(&Q, 1);
  qs_PrintQueue(&Q);
  qs_EnQueue(&Q, 2);
  qs_PrintQueue(&Q);
  qs_EnQueue(&Q, 3);
  qs_PrintQueue(&Q);
  qs_EnQueue(&Q, 4);
  qs_PrintQueue(&Q);
  qs_EnQueue(&Q, 5);
  qs_PrintQueue(&Q);
  qs_EnQueue(&Q, 6);
  qs_PrintQueue(&Q);
  qs_DeQueue(&Q);
  qs_PrintQueue(&Q);
  qs_DeQueue(&Q);
  qs_PrintQueue(&Q);
  qs_DeQueue(&Q);
  qs_PrintQueue(&Q);
  qs_DeQueue(&Q);
  qs_PrintQueue(&Q);
  qs_DeQueue(&Q);
  qs_PrintQueue(&Q);
  qs_DeQueue(&Q);
  qs_PrintQueue(&Q);
//qs_InitQueue
//qs_EnQueue
//qs_DeQueue
//qs_IsQueueEmpty
//qs_IsQueueFull
#endif


#if 0
//linked stack#####
  qs_LSTACK_NODE temp_lstack;
  qs_LSTACK_NODE_PTR temp_lstack_ptr = &temp_lstack;
  qs_lStackInit(temp_lstack_ptr);
  qs_lStackPop(temp_lstack_ptr);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPush(temp_lstack_ptr, 1);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPush(temp_lstack_ptr, 2);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPush(temp_lstack_ptr, 3);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPush(temp_lstack_ptr, 4);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPush(temp_lstack_ptr, 5);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPop(temp_lstack_ptr);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPop(temp_lstack_ptr);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPop(temp_lstack_ptr);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPop(temp_lstack_ptr);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPop(temp_lstack_ptr);
  qs_lStackPrint(temp_lstack_ptr);
  qs_lStackPop(temp_lstack_ptr);
  qs_lStackPrint(temp_lstack_ptr);

#endif


#if 1

  //here is a global power state definition
    unsigned int SocSystemPowerState = POWER_OFF;

    unsigned int LoadCPUImageReady = 0; //just for Core1~3,set by cmm
    unsigned int LoadCPUImageRequest = 0; //set by Core0 in C
    unsigned int LoadWifiReady = 0; //set by cmm, to load wifi image, how get the wifi feedback?
    unsigned int LoadWifiRequest = 0; //set by Core0 in C

    unsigned int SystemError = 0;
    unsigned int SystemNum = 0;

    unsigned int PowerOnEnable = POWER_MODE_TRAN_ENABLE;
    unsigned int LowPowerEnterEnable = POWER_MODE_TRAN_ENABLE;
    unsigned int LowPowerExitEnable = POWER_MODE_TRAN_ENABLE;


    i = 5;
  while(i>0)
    {
      i--;
      switch(SocSystemPowerState)
      {
      case POWER_OFF:
          printf("here is Power Off state \n");
          if (PowerOnEnable == POWER_MODE_TRAN_ENABLE)
            {
          //power mode transition from power off to power on function// initial function
          //normal basic check for next power state(power on)
          //SystemError = SOCPowerOnBasicCheck();
          //if succeed, set the power state as Power on state
              SocSystemPowerState = POWER_ON;
            }else
              {
                  printf("do not power on initial\n");
              }
          break;
      case POWER_ON:
          printf("here is PowerOn state\n");
          if(LowPowerEnterEnable == POWER_MODE_TRAN_ENABLE)
            {
          //power mode transition from power on to low power function
          //SystemError = SOCLowPowerEnter();
          //normal basic check for next power state(low power)
          //SystemError = SOCLowPowerBasicCheck();
          //if succeed, set the power state as low power state
              SocSystemPowerState = LOW_POWER;
            }else
              {
                   printf("do those function test in power on state\n");
              }
          break;
      case LOW_POWER:
          printf("here is LowPower state\n");
          if(LowPowerExitEnable == POWER_MODE_TRAN_ENABLE)
            {
          //power mode transition from low power to power on  function
          //SystemError = SOCLowPowerExit();
          //normal basic check for next power state(low power)
          //SystemError = SOCPowerOnBasicCheck();
          //if succeed, set the power state as PowerOn state
              SocSystemPowerState = POWER_ON;
            }else
              {
                   printf("do those function test in low power state\n");
              }
          break;
      default :
          printf("abnormal branch in system power state case\n");
          break;
      }
    }

#endif


#if 0
  //to check a number list in lmbench
  //typedef  long unsigned int  LUI_NUB
  LUI_NUB LOWER = 512;
  LUI_NUB len = 1024*1024;
  LUI_NUB range = 0;
  LUI_NUB step(LUI_NUB k);

  printf("len is : %d (1024*1024)\n", len);

  for (range = LOWER; range <= len; range = step(range)) {
                            // loads(len, range, stride, parallel,
                             //      warmup, repetitions);
      printf("range is : %dk : %d\n", (range/1024),range);
                       }



#endif

//================================================================//
  i++;
  printf("\n##this is end of %s in %s##\n", __func__, __FILE__);
  printf("\n^-^ ##this is end of ctest_qshan## ^-^\n");
return 0;
}

//to check a number list in lmbench
LUI_NUB step(LUI_NUB k)
{
       if (k < 1024) {
              k = k * 2;
        } else if (k < 4*1024) {
              k += 1024;
              } else {
                  LUI_NUB s;

                     for (s = 4 * 1024; s <= k; s *= 2)
                           ;
                     k += s / 4;
              }
       return (k);
}
