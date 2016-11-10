/*
 * practice.h
 *
 *  Created on: Nov 4, 2016
 *      Author: qshan
 */

#ifndef SRC_QSHAN_PRACTICE_H_
#define SRC_QSHAN_PRACTICE_H_
#include <stdio.h>

#define NUMBEROFARRAYD1(x)  (sizeof(x)/sizeof(x[0]))

int sort_int(int Array[], int size_array);
void print_int_array(int Array[], int size_array);


#define data_dlinst_node int

#if 0
struct dlist_node{
    data_dlinst_node data;
    struct dlist_node *piror, *next;
};

typedef struct dlist_node QS_DLIST_NODE;
#endif

#if 1
typedef struct dlist_node{
    data_dlinst_node data;
    struct dlist_node *piror, *next;
} QS_DLIST_NODE;
#endif

typedef QS_DLIST_NODE (*QS_DLIST_PTR);



#endif /* SRC_QSHAN_PRACTICE_H_ */
