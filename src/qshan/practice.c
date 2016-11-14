/*
 * practice.c
 *
 *  Created on: Nov 4, 2016
 *    Author: qshan
 */
#include <stdio.h>
#include <stdlib.h>
#include <practice.h>

int sort_int(int Array[], int size_array)
{
  printf("\nHello from sort function!\n");
  int i,j;
  int temp;

//  for (i=1; i<(sizeof(Array)/sizeof(Array[0]));i++)
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


///////
QS_DLIST_PTR qs_dlist_create()
{
  QS_DLIST_PTR qs_dlist_new_ptr = (QS_DLIST_PTR)malloc(sizeof(QS_DLIST_NODE));
  qs_dlist_new_ptr->next = NULL;
  qs_dlist_new_ptr->piror = NULL;
  printf("\n Here is the end of %s \n", __func__);
  return qs_dlist_new_ptr;
}

int qs_dlist_insert_R(QS_DLIST_PTR listptr, data_dlinst_node pos, data_dlinst_node data)
{
  //add code here
  QS_DLIST_PTR p = listptr;
  QS_DLIST_PTR newnodeptr;
  //if list is empty
  if ((p->next == NULL) && (p->piror == NULL) && (p->data == NULL))
    {
      printf("current list is empty\n");
      printf("insert %d\n", data);
      newnodeptr = (QS_DLIST_PTR)malloc(sizeof(QS_DLIST_NODE));
      p->data = data;
      p->next= NULL;
      p->piror = NULL;
      listptr = newnodeptr;
      return 0;
    }
  //if find node
  do{

      if ((p->next == NULL))
        {
          //if this node is in the end or do not find
          if (p->data != pos)
            {
              //therer is no this node
              printf("do not find %d, insert end \n", pos);
            }else
              {
                //there is node in the end
                printf("find %d in end, insert %d \n", pos, data);
              }

          newnodeptr = (QS_DLIST_PTR)malloc(sizeof(QS_DLIST_NODE));
          newnodeptr->data = data;
          newnodeptr->next = NULL;
          p->next = newnodeptr;
          newnodeptr->piror = p;
          return 0;
        }else
          {
            // if p->next != NULL
            if (p->data == pos)
            {
              //insert node
              printf("find %d, insert %d \n", pos, data);
              newnodeptr = (QS_DLIST_PTR)malloc(sizeof(QS_DLIST_NODE));
              newnodeptr->data = data;
              newnodeptr->next = p->next;
              p->next->piror = newnodeptr;
              p->next = newnodeptr;
              newnodeptr->piror = p;
              return 0;
            }else
            {
              p = p->next;
            }
          }


    }while(1);

  printf("\n Here is the end of %s \n", __func__);
}

int qs_dlist_insert_L()
{
  //add code here
  printf("\n Here is the end of %s \n", __func__);
  return 0;
}

int qs_dlist_delete(QS_DLIST_PTR listptr, data_dlinst_node data)
{
  //add code here
  QS_DLIST_PTR p = listptr;
  QS_DLIST_PTR newnodeptr;
  //if list is empty
  if ((p->next == NULL) && (p->piror == NULL) && (p->data == NULL))
    {
      printf("current list is empty\n");
      printf("do not find %d\n", data);
      return 0;
    }

  //start search and delete in the list
  do{

      if ((p->piror == NULL))
        {
          //if this node is in the head
          if (p->data == data)
            {
              //data is in the head
              printf("find %d in head, delete \n", data);
              newnodeptr = p;
              p->next->piror = NULL;
              listptr = listptr->next;
              free(newnodeptr);
              return 0;
            }else
              {
                //find next
                p = p->next;
              }
        }else if (p->next != NULL)
          {
            // if p->next != NULL
            if (p->data == data)
            {
              //find the data in the list
              printf("find %d, delete \n", data);
              newnodeptr = p;
              p->next->piror = p->piror;
              p->piror->next = p->next;
              free(newnodeptr);
              return 0;
            }else
            {
              //find next
              p = p->next;
            }
          }else if (p->data == data)
            {
              //data is in end of list
              printf("find %d, in the end \n",  data);
              newnodeptr = p;
              p->piror->next = NULL;
              free(newnodeptr);
              return 0;
            } else
              {
                printf("do not fine %d in dlist \n", data);
                return 0;
              }
    }while(1);

  printf("\n Here is the end of %s \n", __func__);
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

int qs_dlist_print(QS_DLIST_PTR listptr)
{
  //add code here
  QS_DLIST_PTR p = listptr;
  printf("current list is: {");
  if ((p->next == NULL) & (p->piror == NULL))
    {
      printf("empty\n");
      //printf("insert %d\n", data);
      return 0;
    }
  while(1)
    {
        //insert node
        printf("%d", p->data);

    if ((p->next == NULL))
      {
        printf("}\n");
        return 0;
      }
    printf(", ");
    p = p->next;
    };

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
