#include "n_core.h"

/*
 * TODO: Very ugly. Fix asap.
 */
void lnode_clear(LNode *node) {
	LNode *curr = node;
	LNode *next;
	while (curr != NULL) {
		if (curr->data != NULL) {
			free_ndarr(curr->data);
		}
		next = curr->next;
		free(curr);
		curr = next;
	}
	node = NULL;
}

void lnode_push(LNode *node, NDARR *data) {
	LNode *curr = node;
	LNode *newnode = (LNode*) malloc(sizeof(LNode));
	newnode->data = data;
	newnode->next = NULL;

	while (curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = newnode;
}

void lnode_traverse(LNode *node) {
	LNode *curr = node;
	while (curr->next != NULL) {
		curr = curr->next;
		printf("%d\n", curr->data->id);
	}
}

void n_cleanup() {
	lnode_clear(LLIST);
}

void free_ndarr(NDARR *a) {
        free(a->data);
        free(a);
}

long shape_to_size(long ndim, long *shape) {
        long prod = 1;
        for (int i = 0; i < ndim; ++i) prod *= *(shape + i);
        return prod;
}

void fill_with_constant(NDARR *ndarr, double val) {
        for (int i = 0; i < ndarr->size; ++i) {
                ndarr->data[i] = val;
        }
}

void n_init() {
	GLOBAL_NDARR_COUNT = 0;
	LLIST = (LNode*) malloc(sizeof(LNode));
	LLIST->data = NULL;
	LLIST->next = NULL;
}

NDARR *create_empty_ndarr(long ndim, long *shape) {
        NDARR *res = malloc(sizeof(*res));
        res->shape = shape;
        res->ndim = ndim;
        res->size = shape_to_size(ndim, res->shape);
        res->data = malloc(res->size * sizeof(double));
        res->is_leaf = 1;
	res->id = GLOBAL_NDARR_COUNT;
        res->requires_grad = 0;
	res->backward_func = NULL;
	
	//GLOBAL_TRACKER[GLOBAL_NDARR_COUNT] = res;
	lnode_push(LLIST, res);
	++GLOBAL_NDARR_COUNT;

        return res;
}

NDARR *create_ndarr(long ndim, long *shape, double *data) {
        NDARR *res = create_empty_ndarr(ndim, shape);
        memcpy(res->data, data, res->size * sizeof(data));
        return res;
}

NDARR *create_ones(long ndim, long *shape) {
        NDARR *res = create_empty_ndarr(ndim, shape);
        fill_with_constant(res, 1.0);
        return res;
}
