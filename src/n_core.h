#ifndef CORE_H
#define CORE_H

#include <stdbool.h>

#define MAX_NUM_NODE 1024

typedef struct _ndarr NDARR;
struct _ndarr {
        double* data;
        long* shape;
        long* stride;
        long size;
        long ndim;
        int requires_grad;
        int is_leaf;
        NDARR **prevs;
};

NDARR *GLOBAL_TRACKER;

void finalize();
void free_ndarr(NDARR *a);
long *int_arr_from_arglist(long count, ...);
long shape_to_size(long ndim, long *shape);

void init();
void fill_with_constant(NDARR *ndarr, double val);
void reshape(NDARR *ndarr, long* new_shape);

NDARR *create_empty_ndarr(long ndim, long *shape);
NDARR *create_ndarr(long ndim, long *shape, double *data);
NDARR *create_ones(long ndim, long *shape);

#endif