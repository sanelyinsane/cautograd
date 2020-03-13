#include <stdlib.h>
#include "n_core.h"

int shape_to_size(int ndim, int *shape) 
{
        int prod = 1;
        for (int i = 0; i < ndim; ++i) prod *= *(shape + i);
        return prod;
}

void fill_with_constant(NDARR *ndarr, double val) {
        for (int i = 0; i < ndarr->size; ++i) {
                ndarr->data[i] = val;
        }
}

NDARR *create_empty_ndarr(int ndim, int *shape)
{
        NDARR *res = malloc(sizeof(*res));
        res->shape = shape;
        res->size = shape_to_size(ndim, shape);
        res->data = calloc(res->size, sizeof(double));

        return res;
}

NDARR *create_ones(int ndim, int *shape)
{
        NDARR *res = create_empty_ndarr(ndim, shape);
        fill_with_constant(res, 1.0);

        return res;
}