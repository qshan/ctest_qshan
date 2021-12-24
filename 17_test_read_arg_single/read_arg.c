#include <stdio.h>
#include "string.h"

  //macro and data type here
  #define MAX_STRING_LENGTH 100

  //function list
  int arg_read(int argc ,char *argv[], char input_arg_list[][3][MAX_STRING_LENGTH]);
  int print_arg_list(char input_arg_list[][3][MAX_STRING_LENGTH]);


int arg_read(int argc ,char *argv[] ,char input_arg_list[][3][MAX_STRING_LENGTH])
{
  int i, j;//for arg print control
  int value_returned=0;

  #if PRINT_DEBUG_ENABLE
    printf("--------------------------------------------------\n");
    printf("Running the %s() in %s\n" ,__func__ ,__FILE__);
    printf("--------------------------------------------------\n");
  #endif

  #if 1
  {
    //ToCheck
    /*
    #define MAX_STRING_LENGTH 100
    char input_arg_list[][3][MAX_STRING_LENGTH]=
    {
       {"--port"  ,""         ,"set port name info"}
      ,{"--file"  ,""         ,"set file name"}
      ,{"--end--" ,"--end--"  ,"reserved keywords"}
    };
    */
    printf("------------------------------\n");

    if ((strcasecmp (argv[1], "--help") == 0))
    {
      printf("##### Help arguments format:\n");
      printf("##### --keyword key_value_need_input\n");
      printf("##### keyword supported lists:\n");
      for (j=0;;j++)
      {
        if ((strcasecmp (input_arg_list[j][0], "--end--") == 0)){break;}
        printf("#####     %s : %s\n" ,input_arg_list[j][0] ,input_arg_list[j][2]);
      }

      //return 1
      value_returned =1;
    }
    else
    {
      for(i=1;i<argc;)
      {
        for (j=0;;j++)
        {
          if ((strcasecmp (input_arg_list[j][0], "--end--") == 0)){break;}

          if ((strcasecmp (argv[i], input_arg_list[j][0]) == 0))
          {
            strncpy(input_arg_list[j][1], argv[i+1] ,strlen(argv[i+1]));
            printf("##### Get %s info: %s\n" ,input_arg_list[j][0] ,input_arg_list[j][1]);
          }
        }
        i=i+2;
      }

      //return 0
      value_returned =0;
    }

  }
  #endif

  //return 0;
  return value_returned;
}


int print_arg_list(char input_arg_list[][3][MAX_STRING_LENGTH])
{
  int value_returned =0;
  int i=0;

  #if PRINT_DEBUG_ENABLE
    printf("--------------------------------------------------\n");
    printf("Running the %s() in %s\n" ,__func__ ,__FILE__);
    printf("--------------------------------------------------\n");
  #endif

  printf("------------------------------\n");
  printf("check the input_arg_list info\n");
  for (i=0;;i++)
  {
    if ((strcasecmp (input_arg_list[i][0], "--end--") == 0)){break;}
    printf("#####     %s : %s\n" ,input_arg_list[i][0] ,input_arg_list[i][1]);
  }

  return value_returned;
}

int main(int argc ,char *argv[])
//int main_try(int argc ,char *argv[])
{
  int value_returned=0;

  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("===================================================\n");
    printf("hello read_argu \n");
    printf("\n");
  #endif

  #if 1
  {
    int i=0;
    printf("------------------------------\n");
    printf("##### Get argc is %d\n"    , argc);
    printf("##### Get argv is ");
    for(i=0;i<argc;i++)
    {
      printf(" %s" , argv[i]);
    }
    printf("\n");

    printf("------------------------------\n");

    for(i=0;i<argc;i++)
    {
      printf("##### Get argv[%d] is %s\n" ,i ,argv[i]);
    }
  }
  #endif

  #if 1
  {
    //ToCheck
    //#define MAX_STRING_LENGTH 100
    char input_arg_list1[][3][MAX_STRING_LENGTH]=
    {
       {"--port"  ,""         ,"set port name info"}
      ,{"--file"  ,""         ,"set file name"}
      ,{"--end--" ,"--end--"  ,"reserved keywords"}
    };

    #if 1
      //check the argument list contents before updated
      print_arg_list(input_arg_list1);
    #endif

    printf("------------------------------\n");

    printf("Start call arg_read function\n");
    value_returned  = arg_read(argc ,argv ,input_arg_list1);
    printf("exit arg_read function now\n");

    #if 0
      int i=0;
      printf("------------------------------\n");
      printf("check the input_arg_list info\n");
      for (i=0;;i++)
      {
        if ((strcasecmp (input_arg_list1[i][0], "--end--") == 0)){break;}
        printf("#####     %s : %s\n" ,input_arg_list1[i][0] ,input_arg_list1[i][1]);
      }
    #endif

    #if 1
      //check the argument list contents updated
      print_arg_list(input_arg_list1);
    #endif

  }
  #endif


  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("Bye read_argu \n");
    printf("===================================================\n");
    printf("\n");
  #endif

  printf("------------------------------\n");
  printf("value_returned is %d\n" ,value_returned);
  return value_returned;

}
