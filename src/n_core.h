#ifndef CORE_H
#define CORE_H

struct _ndarr {
        double* data;
        int* shape;
        int size;
};
typedef struct _ndarr NDARR;

int shape_to_size(int ndim, int *shape);
void fill_with_constant(NDARR *ndarr, double val);

NDARR *create_empty_ndarr(int ndim, int *shape);
NDARR *create_ones(int ndim, int *shape);

#endif