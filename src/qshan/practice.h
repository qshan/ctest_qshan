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

#ifndef NULL
#ifdef(__cplusplus)
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif



#define NUMBEROFARRAYD1(x)  (int)(sizeof(x)/sizeof(x[0]))

//there is 3 power state definition here:
#define POWER_OFF 0
#define POWER_ON  1
#define LOW_POWER 3
#define POWER_MODE_TRAN_ENABLE 1
#define POWER_MODE_TRAN_DISABLE 0

//here is a global power state definition
  extern unsigned int SocSystemPowerState;

  extern unsigned int LoadCPUImageReady; //just for Core1~3,set by cmm
  extern unsigned int LoadCPUImageRequest; //set by Core0 in C
  extern unsigned int LoadWifiReady; //set by cmm, to load wifi image, how get the wifi feedback?
  extern unsigned int LoadWifiRequest; //set by Core0 in C

  extern unsigned int SystemError;
  extern unsigned int SystemNum;

  extern unsigned int PowerOnEnable;
  extern unsigned int LowPowerEnterEnable;
  extern unsigned int LowPowerExitEnable;


  typedef  long unsigned int  LUI_NUB;


//define the dlinst
#if 1
//qs_DListDataType
#define qs_DListDataType int
struct dlist_node{
  qs_DListDataType data;
  struct dlist_node *piror, *next;
};
typedef struct dlist_node qs_DLIST_NODE;
typedef struct dlist_node *qs_DLIST_PTR;
//typedef qs_DLIST_NODE *qs_DLIST_PTR;
#else
typedef struct dlist_node{
  qs_DListDataType data;
  struct dlist_node *piror, *next;
} qs_DLIST_NODE, *qs_DLIST_PTR;
#endif
//declare a struct
//qs_DLIST_NODE struct_customer_name;
//declare a pointer of struct
//qs_DLIST_PTR struct_customer_pointer;
//qs_DLIST_NODE *struct_customer_pointer;

//qs_Queue
#define qs_QueueDataType int
typedef struct queue
{
  //this struct need a cell to diff the full and empty
  int queuesize;
  int head,tail;
  qs_QueueDataType *q;
} qs_QUEUE;

//qs_LStack
#define qs_LStackType int
typedef struct lStackNode{
  qs_LStackType data;
  struct lStackNode *next;
} qs_LSTACK_NODE, *qs_LSTACK_NODE_PTR;

//qs_BiTree
#define qs_TreeDataType int
typedef struct BiTNode
{
  qs_TreeDataType data;
  struct BiTNode *parent, *lchild, *rchild;
} qs_BITREE_NODE, *qs_BITREE_PTR;

//qs_BinarySearchTree
#define qs_BSTreeDataType int
typedef struct BinarySearchTreeNode
{
  qs_BSTreeDataType data; //the data of this node
  //int data_index; //the location of data in data array
  struct BinarySearchTreeNode *parent, *lchild, *rchild;
} qs_BSTREE_NODE, *qs_BSTREE_PTR;

qs_BSTREE_PTR qs_CreateBSTNode(qs_BSTreeDataType keynum);
qs_BSTREE_PTR qs_SearchBSTNode(qs_BSTREE_PTR tree, qs_BSTreeDataType number);
qs_BSTREE_PTR qs_MinBSTNode(qs_BSTREE_PTR tree);
qs_BSTREE_PTR qs_MaxBSTNode(qs_BSTREE_PTR tree);
qs_BSTREE_PTR qs_BSTSuccessor(qs_BSTREE_PTR tree);
qs_BSTREE_PTR qs_BSTPredecessor(qs_BSTREE_PTR tree);
int qs_InsertBSTNode(qs_BSTREE_PTR *tree, qs_BSTREE_PTR z);
int qs_DeleteBSTNode(qs_BSTREE_PTR *tree, qs_BSTREE_PTR z);

//the storage format for Tree
/////1)parent  format
//qs_PTreeMaxDataSize is total node number of this tree.
//nodes[r].parent is 0 when this node is root node
//nodes[i].data is the data of this node
//nodes[i].parent is the location of its parent. in the array?
#define qs_PTreeMaxDataSize 100
typedef int qs_PTreeElemDataType;
typedef struct PTreeNode
{
  qs_PTreeElemDataType data; //data of this node
  int parent_index; // the location of it parent in the array
} qs_PTREENODE;

typedef struct
{
  qs_PTREENODE nodes[qs_PTreeMaxDataSize]; //array for the data of tree nodes
  int r, NumberOfNodes; //location of root node, and number of nodes
} qs_PTREE;

/////2)child format
//qs_ChildTreeMaxDataSize is total number  of this tree's child lists.
//suppose there is degree k for very parent node, that means there is k child for very parent node
//there are multi-child in root node
//there is list in every child node.
//
#define qs_ChildTreeMaxDataSize 100
typedef int qs_ChildTreeElemDataType;
typedef struct ChildTreeNode
{
  //qs_ChildTreeElemDataType data; //data of this child
  int child_index;  //the location of child node
  struct ChildTreeNode *next_ptr; //pointer to next child in this node
} qs_CHILDTREENODE, *qs_CHILDTREENODE_PTR;

typedef struct ChildTreeNodeBox  //head structure
{
  qs_ChildTreeElemDataType data;
  qs_CHILDTREENODE_PTR firstchild_ptr; //the pointer of child list.
  //int degree; //this is optional parameter
} qs_ChildTreeNodeBox;

typedef struct
{
  qs_ChildTreeNodeBox nodes[qs_ChildTreeMaxDataSize]; //array for child list
  int root_index, NumberOfNodes; //location of root node, and number of total nodes
} qs_CHILDTREE;

/////3)child sibling format
//#define qs_CSTreeMaxDataSize 100
typedef int qs_CSTreeElemDataType;
typedef struct CSTreeNode
{
  qs_CSTreeElemDataType data; //data of this node
  struct CSTreeNode *firstchild, *rightsibling;
  //int parent; // the location of it parent in the array
} qs_CSTREENODE, *qs_CSTREE_PTR;






//////// function name list here

//sort#####
int sort_int(int Array[], int size_array);
void print_int_array(int Array[], int size_array);

//list#####
qs_DLIST_PTR qs_dlist_create();
int qs_dlist_insert_R(qs_DLIST_PTR listptr, qs_DListDataType pos, qs_DListDataType data);
int qs_dlist_insert_L();
int qs_dlist_delete(qs_DLIST_PTR listptr, qs_DListDataType data);
int qs_dlist_delete_L();
int qs_dlist_delete_R();
int qs_dlist_print(qs_DLIST_PTR listptr);
int qs_dlist_length();
int qs_dlist_find();
int qs_dlist_find_L();
int qs_dlist_find_R();
//

//queue##### FIFO
int qs_InitQueue(qs_QUEUE *Q, int queuesize);
int qs_EnQueue(qs_QUEUE *Q, qs_QueueDataType key);
qs_QueueDataType qs_DeQueue(qs_QUEUE *Q);
int qs_PrintQueue(qs_QUEUE *Q);
//qs_IsQueueEmpty
//qs_IsQueueFull


//linked stack##### LIFO Last In First Out.
int qs_lStackInit(qs_LSTACK_NODE_PTR head);
int qs_lStackPush(qs_LSTACK_NODE_PTR head, qs_LStackType data);
qs_LStackType qs_lStackPop(qs_LSTACK_NODE_PTR head);
int qs_lStackPrint(qs_LSTACK_NODE_PTR head);

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
