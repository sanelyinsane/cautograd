#include "n_math.h"

void bfunc(double (*f)(double, double), NDARR *a, NDARR *b, NDARR *out) 
{
        for (int i = 0; i < out->size; ++i) {
                out->data[i] = (*f)(a->data[i], b->data[i]);
        }
}

double _sub(double a, double b) { return a - b; }
double _add(double a, double b) { return a + b; }
double _mul(double a, double b) { return a * b; }


void n_add(NDARR *a, NDARR *b, NDARR *out) { bfunc(_add, a, b, out); }
void n_sub(NDARR *a, NDARR *b, NDARR *out) { bfunc(_sub, a, b, out); }
void n_mul(NDARR *a, NDARR *b, NDARR *out) { bfunc(_mul, a, b, out); }

NDARR *add(NDARR *a, NDARR *b) {
        NDARR *res = create_empty_ndarr(a->ndim, a->shape);
        n_add(a, b, res);
        return res;
}