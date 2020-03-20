#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_NODE 1024

int  GLOBAL_NDARR_COUNT;

typedef struct _ndarr NDARR;
struct _ndarr {
        double *data;
        long   *shape;
        long   *strides;
        long   size;
        long   ndim;
        int    requires_grad;
        int    is_leaf;
	int    id;
	void   (*backward_func)(NDARR **, NDARR*);
        NDARR  **prevs;
};

/*
 * A linked list to track the created NDARRs.
 */
typedef struct _lnode LNode;
struct _lnode {
	NDARR *data;
	LNode *next;
};
LNode *LLIST;
void lnode_clear(LNode *node);
void lnode_push(LNode *node, NDARR *data);
void lnode_traverse(LNode *node);

void n_cleanup();
void n_init();
void free_ndarr(NDARR *a);
long shape_to_size(long ndim, long *shape);

void fill_with_constant(NDARR *ndarr, double val);
void reshape(NDARR *ndarr, long* new_shape);

NDARR *create_empty_ndarr(long ndim, long *shape);
NDARR *create_ndarr(long ndim, long *shape, double *data);
NDARR *create_ones(long ndim, long *shape);

#endif
