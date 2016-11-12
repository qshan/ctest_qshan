/*
 * practice.c
 *
 *  Created on: Nov 4, 2016
 *      Author: qshan
 */
#include <stdio.h>
#include <stdlib.h>
#include <practice.h>

int sort_int(int Array[], int size_array)
{
    printf("\nHello from sort function!\n");
    int i,j;
    int temp;

//    for (i=1; i<(sizeof(Array)/sizeof(Array[0]));i++)
    for (i=1; i<(size_array);i++)
    {
        temp = Array[i];
        for(j=i-1;j>=0;j--)
        {
            if (temp < Array[j])
            {
                Array[j+1] = Array[j];
            }else
            {
                Array[j+1] = temp;
                break;
            }

            if(j==0)
            {
                Array[j] = temp;
            }
        }
    }
    return 0;
}

void print_int_array(int Array[], int size_array)
{
    int i=0;
    printf("Array is {");
    for (i=0; i<(size_array);i++)
    {
        printf("%d, ", Array[i]);
    }
    printf("}");
}

QS_DLIST_PTR qs_dlist_create()
{
    QS_DLIST_PTR qs_dlist_new_ptr = (QS_DLIST_PTR)malloc(sizeof(QS_DLIST_NODE));
    qs_dlist_new_ptr->next = NULL;
    qs_dlist_new_ptr->piror = NULL;
    printf("\n Here is the end of %s \n", __func__);
    return qs_dlist_new_ptr;
}

int qs_dlist_insert_before()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_insert_R()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_insert_L()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_delete()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_delete_L()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_delete_R()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_print()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_length()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_find()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_find_L()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

int qs_dlist_find_R()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    return 0;
}

//int qs_dlist_ListTraverse()


#if 0
QS_DLIST_PTR qs_dlist_()
{
    //add code here
    printf("\n Here is the end of %s \n", __func__);
    //printf("\n Here is code line number %d in %s \n", __LINE__, __FILE__);
    return 0;
}
#endif
