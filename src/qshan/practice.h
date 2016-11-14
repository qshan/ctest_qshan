/*
 * practice.h
 *
 *  Created on: Nov 4, 2016
 *    Author: qshan
 */

#ifndef SRC_QSHAN_PRACTICE_H_
#define SRC_QSHAN_PRACTICE_H_
#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFARRAYD1(x)  (int)(sizeof(x)/sizeof(x[0]))






//define the dlinst
#if 1
#define data_dlinst_node int
struct dlist_node{
  data_dlinst_node data;
  struct dlist_node *piror, *next;
};
typedef struct dlist_node QS_DLIST_NODE;
typedef struct dlist_node *QS_DLIST_PTR;
//typedef QS_DLIST_NODE *QS_DLIST_PTR;
#else
typedef struct dlist_node{
  data_dlinst_node data;
  struct dlist_node *piror, *next;
} QS_DLIST_NODE, *QS_DLIST_PTR;
#endif
//declare a struct
//QS_DLIST_NODE struct_customer_name;
//declare a pointer of struct
//QS_DLIST_PTR struct_customer_pointer;
//QS_DLIST_NODE *struct_customer_pointer;

#define datatype_queue int
typedef struct qs_queue
{
  int queuesize;
  int head,tail;
  datatype_queue *q;
} QS_QUEUE;



//////// function name list here

//sort#####
int sort_int(int Array[], int size_array);
void print_int_array(int Array[], int size_array);

//list#####
QS_DLIST_PTR qs_dlist_create();
int qs_dlist_insert_R(QS_DLIST_PTR listptr, data_dlinst_node pos, data_dlinst_node data);
int qs_dlist_insert_L();
int qs_dlist_delete(QS_DLIST_PTR listptr, data_dlinst_node data);
int qs_dlist_delete_L();
int qs_dlist_delete_R();
int qs_dlist_print(QS_DLIST_PTR listptr);
int qs_dlist_length();
int qs_dlist_find();
int qs_dlist_find_L();
int qs_dlist_find_R();
//

//queue##### FIFO
int qs_InitQueue(QS_QUEUE *Q, int queuesize);
int qs_EnQueue(QS_QUEUE *Q, datatype_queue key);
datatype_queue qs_DeQueue(QS_QUEUE *Q);
int qs_PrintQueue(QS_QUEUE *Q);
//qs_IsQueueEmpty
//qs_IsQueueFull


//stack##### FILO

//tree#####
//BFS - Dreadth First Search
//DFS - Depth First Search
//Tree Traversals, Expression Tree


//graph#####

//BST - Binary Search Tree

//AVL Tree

//B Tree

//Hashing

#endif /* SRC_QSHAN_PRACTICE_H_ */
