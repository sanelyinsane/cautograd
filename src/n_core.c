#include <stdlib.h>
#include <stdarg.h>
#include "n_core.h"

long *int_arr_from_arglist(long count, ...) 
{
        long *res = calloc(count, sizeof(long));
        va_list list;

        va_start(list, count);
        for (int i = 0; i < count; ++i) 
                res[i] = va_arg(list, int);
        va_end(list);

        return res;
}

long shape_to_size(long ndim, long *shape) 
{
        long prod = 1;
        for (int i = 0; i < ndim; ++i) prod *= *(shape + i);
        return prod;
}

void fill_with_constant(NDARR *ndarr, double val) {
        for (int i = 0; i < ndarr->size; ++i) {
                ndarr->data[i] = val;
        }
}

NDARR *create_empty_ndarr(long ndim, long *shape)
{
        NDARR *res = malloc(sizeof(*res));
        res->shape = shape;
        res->ndim = ndim;
        res->size = shape_to_size(ndim, shape);
        res->data = calloc(res->size, sizeof(double));

        return res;
}

NDARR *create_ones(long ndim, long *shape)
{
        NDARR *res = create_empty_ndarr(ndim, shape);
        fill_with_constant(res, 1.0);

        return res;
}