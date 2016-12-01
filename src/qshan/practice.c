/*
 * practice.c
 *
 *  Created on: Nov 4, 2016
 *    Author: qshan
 */
#include <stdio.h>
#include <stdlib.h>
#include <practice.h>

//sort#####
int sort_int(int Array[], int size_array)
{
  printf("\nHello from %s function!\n", __func__);
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


//list#####
qs_DLIST_PTR qs_dlist_create()
{
  //create the dlist head
  qs_DLIST_PTR qs_dlist_new_ptr = (qs_DLIST_PTR)malloc(sizeof(qs_DLIST_NODE));
  qs_dlist_new_ptr->next = qs_dlist_new_ptr;
  qs_dlist_new_ptr->piror = qs_dlist_new_ptr;
  printf("\n%s is ##dlist with head##\n", __func__);
  printf("\nHere is the end of %s \n", __func__);
  return qs_dlist_new_ptr;
}

int qs_dlist_insert_R(qs_DLIST_PTR listptr, qs_DListDataType pos, qs_DListDataType data)
{
  //add code here
  qs_DLIST_PTR p = listptr;
  qs_DLIST_PTR newnodeptr;
  //if list is empty
  if ((p->next == p) && (p->piror == p))
    {
      printf("current list is empty\n");
      printf("insert %d\n", data);
      newnodeptr = (qs_DLIST_PTR)malloc(sizeof(qs_DLIST_NODE));
      newnodeptr->data = data;
      newnodeptr->next = newnodeptr;
      newnodeptr->piror = p;
      p->next= newnodeptr;
      //listptr = newnodeptr;
      return 0;
    }
  //if find node
  do{
      p = p->next;
      if ((p->next == p))
        {
          //if this node is in the end or do not find
          if (p->data != pos)
            {
              //therer is no this node
              printf("not find %d, insert %d in end \n", pos, data);
            }else
              {
                //there is node in the end
                printf("find %d in end, insert %d \n", pos, data);
              }

          newnodeptr = (qs_DLIST_PTR)malloc(sizeof(qs_DLIST_NODE));
          newnodeptr->data = data;
          newnodeptr->next = newnodeptr;
          newnodeptr->piror = p;
          p->next = newnodeptr;
          return 0;
        }else
          {
            // if p->next != p, is not end
            if (p->data == pos)
            {
              //insert node
              printf("find %d, insert %d \n", pos, data);
              newnodeptr = (qs_DLIST_PTR)malloc(sizeof(qs_DLIST_NODE));
              newnodeptr->data = data;
              newnodeptr->next = p->next;
              newnodeptr->piror = p;
              p->next->piror = newnodeptr;
              p->next = newnodeptr;
              return 0;
            }else
              {
                continue;
              }
          }
    }while(1);

  printf("\n Here is the end of %s \n", __func__);
  return 0;
}

int qs_dlist_insert_L()
{
  //add code here
  printf("\n Here is the end of %s \n", __func__);
  return 0;
}

int qs_dlist_delete(qs_DLIST_PTR listptr, qs_DListDataType data)
{
  //add code here
  qs_DLIST_PTR p = listptr;
  qs_DLIST_PTR newnodeptr;
  //if list is empty
  if ((p->next == p) && (p->piror == p))
    {
      printf("current list is empty\n");
      printf("do not find %d\n", data);
      return 0;
    }

  //start search and delete in the list
  do{
      p = p->next;
      if ((p->next == p))
        {
          //if this node is in the end
          if (p->data == data)
            {
              //data is in the end
              printf("find %d in end, delete \n", data);
              newnodeptr = p;
              p->piror->next = p->piror;
              //listptr = p->next;
              free(newnodeptr);
              return 0;
            }else
              {
                //find next
                //p = p->next;
                printf("do not find %d \n", data);
                return 1;
              }
        }else
          {
            // if p->next != p
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
              continue;
            }
          }
    }while(1);

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

int qs_dlist_print(qs_DLIST_PTR listptr)
{
  //add code here
  qs_DLIST_PTR p = listptr;
  printf("current list is: {");
  if ((p->next == p) & (p->piror == p))
    {
      printf("empty\n");
      //printf("insert %d\n", data);
      return 0;
    }
  while(1)
    {
        p = p->next;
        //scan node
        printf("%d", p->data);

    if ((p->next == p))
      {
        printf("}\n");
        return 0;
      }
    printf(", ");
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


#if 1
//queue##### FIFO

int qs_InitQueue(qs_QUEUE *Q, int queuesize)
{
  Q->queuesize = (queuesize +1);
  Q->q = (qs_QueueDataType *)malloc(sizeof(qs_QueueDataType)*(Q->queuesize));
  Q->head = 0;
  Q->tail = 0;
  printf("Hello from %s \n", __func__);
  return 0;
}


int qs_EnQueue(qs_QUEUE *Q, qs_QueueDataType key)
{
  //add code here
  int tail = ((Q->tail+1) % Q->queuesize);
  if (tail == Q->head)
    {
      printf("this queue is full\n");
      printf("not qs_EnQueue %d \n", key);
      return 1;
    }else
      {
        Q->q[Q->tail] = key;
        Q->tail = tail;
        printf("Hello from %s\n", __func__);
        return 0;
      }
}

qs_QueueDataType qs_DeQueue(qs_QUEUE *Q)
{
  //add code here
  qs_QueueDataType key;
  if (Q->tail == Q->head)
    {
      printf("not DeQueue, queue is empty\n");
      return 1;
    }else
      {
        key = Q->q[Q->head];
        Q->head = ((Q->head+1) % Q->queuesize);
        printf("DeQueue, key is %d\n", key);
        return key;
      }
}

int qs_PrintQueue(qs_QUEUE *Q)
{
  //add code here
  int i;
  if(Q->head == Q->tail)
    {
      printf("empty queue now!\n");
      return 1;
    }
  printf("This queue is: {");
  for (i=0; i< (Q->tail - Q->head);i++)
    {
      if (i <((Q->tail - Q->head) - 1))
      {
        printf("%d,", Q->q[Q->head+i]);
      }else
      {
        printf("%d", Q->q[Q->head+i]);
      }
    }
  printf("}\n");
  return 0;
}

//qs_IsQueueEmpty
//qs_IsQueueFull
#endif


#if 1
//linked stack##### LIFO Last In First Out.
int qs_lStackInit(qs_LSTACK_NODE_PTR head)
{
  //add code here
  //head =(qs_LSTACK_NODE_PTR)malloc(sizeof(qs_LSTACK_NODE));
  head->next = head;
  printf("Hello from %s\n", __func__);
  return 0;
}

int qs_lStackPush(qs_LSTACK_NODE_PTR head, qs_LStackType data)
{
  qs_LSTACK_NODE_PTR tempptr = (qs_LSTACK_NODE_PTR)malloc(sizeof(qs_LSTACK_NODE));
  if (head->next == head)
    {
      tempptr->data =data;
      tempptr->next = tempptr;
      head->next = tempptr;
    }else
      {
        tempptr->data =data;
        tempptr->next = head->next;
        head->next = tempptr;
      }
  printf("push %d\n", tempptr->data);
  return 0;
}

qs_LStackType qs_lStackPop(qs_LSTACK_NODE_PTR head)
{
  qs_LSTACK_NODE_PTR tempptr = head;
  qs_LStackType tempdata;

  if(tempptr->next == tempptr)
    {
      printf("no Pop, lStack empty!\n");
      return 1;
    }
  tempptr = tempptr->next;
  tempdata = tempptr->data;
  if (tempptr->next != tempptr)
    {
    printf("Pop %d\n", tempptr->data);
    head->next = tempptr->next;
    free(tempptr);
    return tempdata;
    }else
      {
        printf("Pop %d\n", tempptr->data);
        head->next = head;
        free(tempptr);
        return 1;
      }
}

int qs_lStackPrint(qs_LSTACK_NODE_PTR head)
{
  qs_LSTACK_NODE_PTR tempptr = head;
  if(tempptr->next == tempptr)
    {
      printf("no print, lStack empty!\n");
      return 1;
    }
  printf("Current lStack is: {");
  tempptr = tempptr->next;
  while(1)
    {
      if (tempptr->next != tempptr)
        {
        printf("%d, ", tempptr->data);
        }else
          {
            printf("%d}\n", tempptr->data);
            break;
          }
      tempptr = tempptr->next;
    }
  return 0;
}
#endif

#if 0
//tree#####
//BFS - Dreadth First Search
//DFS - Depth First Search
//Tree Traversals, Expression Tree

//print node when come to N; N -> node, L -> left child, R -L right child
//PreOrderTraversal -> N>L>R
//InOrderTraversal -> L>N>R
//PostOrderTraversal -> L>R>N
#endif

#if 0

//graph#####
#endif

#if 1
//BST - Binary Search Tree
qs_BSTREE_PTR qs_CreateBSTNode(qs_BSTreeDataType keynum)
{
  qs_BSTREE_PTR tree = NULL;
  tree = (qs_BSTREE_PTR)malloc(sizeof(qs_BSTREE_NODE));
  tree->data = keynum;
  tree->lchild = NULL;
  tree->rchild = NULL;
  tree->parent = NULL;
  return tree;
}

qs_BSTREE_PTR qs_SearchBSTNode(qs_BSTREE_PTR tree, qs_BSTreeDataType number)
{
  while(tree != NULL && number != tree->data)
    {
      if (number < tree->data)
        tree = tree->lchild;
      else
        tree = tree->rchild;
    }
  return tree;
}

qs_BSTREE_PTR qs_MinBSTNode(qs_BSTREE_PTR tree)
{
  while(tree->lchild != NULL)
    {
      tree = tree->lchild;
    }
  return tree;
}

qs_BSTREE_PTR qs_MaxBSTNode(qs_BSTREE_PTR tree)
{
  while(tree->rchild != NULL)
    {
      tree = tree->rchild;
    }
  return tree;
}

qs_BSTREE_PTR qs_BSTSuccessor(qs_BSTREE_PTR tree)
{
  qs_BSTREE_PTR y;
  if (tree->rchild != NULL)
    return qs_MinBSTNode(tree->rchild);
  y = tree->parent;
  while(y != NULL && tree == y->rchild)
    {
      tree = y;
      y = y->parent;
    }
  return y;
}

qs_BSTREE_PTR qs_BSTPredecessor(qs_BSTREE_PTR tree)
{
  qs_BSTREE_PTR y;
  if (tree->lchild != NULL)
    return qs_MaxBSTNode(tree->lchild);
  y = tree->parent;
  while(y != NULL && tree == y->lchild)
    {
      tree = y;
      y = y->parent;
    }
  return y;
}

int qs_InsertBSTNode(qs_BSTREE_PTR *tree, qs_BSTREE_PTR z)
{
  qs_BSTREE_PTR x, y;
  y = NULL;
  x = *tree;
  while (x != NULL)
    {
      y = x;
      if (z->data < x->data)
        x = x->lchild;
      else
        x = x->rchild;
    }
  z->parent = y;
  if (y == NULL)
    *tree = z;
  else if(z->data < y->data)
    y->lchild = z;
  else
    y->rchild = z;
  return 0;
}

//check here to get detail information
//http://blog.csdn.net/fengchaokobe/article/details/7551055
int qs_DeleteBSTNode(qs_BSTREE_PTR *tree, qs_BSTREE_PTR z)
{
  qs_BSTREE_PTR x, y;
  if (z->lchild == NULL || z->rchild == NULL)
    y = z;
  else
    y = qs_BSTSuccessor(&(**tree));  //??? why???

  if (y->lchild != NULL)
    x = y->lchild;
  else
    x = y->rchild;

  if (x != NULL)
    x->parent = y->parent;
  if (y->parent == NULL)
    {
      (*tree) = x;
    }
  else if (y == y->parent->lchild)
    y->parent->lchild = x;
  else
    y->parent->rchild = x;

  if (y !=z )
    z->data = y->data;
  free(y);
  y=NULL;

  return 0;
}

//BST - Binary Search Tree end
#endif

#if 0
//AVL Tree
#endif

#if 0
//B Tree
#endif

#if 0
//Hashing
#endif


#if 0

{
  //add code here
  printf("\n Here is the end of %s \n", __func__);
  //printf("\n Here is code line number %d in %s \n", __LINE__, __FILE__);
  return 0;
}
#endif
