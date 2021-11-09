#include <stdio.h>

//#include "test14.h"
#include "arg_read.h"
#include "string.h"

//int arg_read(char *argv[], char *input_arg_list[][3][MAXSTRING_LENGTH])
int arg_read(int argc ,char *argv[] ,char input_arg_list[][3][MAX_STRING_LENGTH])
{
  int i, j;//for arg print control
  int value_returned=0;

  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("Running in %s\n", __func__);
    printf("\n");
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
        //printf("------------------------------\n");
        //printf("##### Check argv[%d] info: %s\n" ,i ,argv[i]);
        for (j=0;;j++)
        {
          //printf("##### Check input_arg_list[%d][0] info: %s\n" ,i ,input_arg_list[j][0]);
          if ((strcasecmp (input_arg_list[j][0], "--end--") == 0)){break;}

          if ((strcasecmp (argv[i], input_arg_list[j][0]) == 0))
          //if ((strcmp (argv[i], input_arg_list[j][0]) == 0))
          {
            //printf("##### get input_arg_list[j][0] info: %s\n", argv[i+1]);
            //strcpy(input_arg_list[j][1], argv[i+1]);
            //TODO//strncpy(input_arg_list[j][1], argv[i+1] ,MAX_STRING_LENGTH);
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

  printf("------------------------------\n");
  printf("check the input_arg_list info\n");
  for (i=0;;i++)
  {
    if ((strcasecmp (input_arg_list[i][0], "--end--") == 0)){break;}
    printf("#####     %s : %s\n" ,input_arg_list[i][0] ,input_arg_list[i][1]);
  }

  return value_returned;
}
